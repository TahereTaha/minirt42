/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:01:14 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/17 13:53:05 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "scene.h"
#include "renderer.h"

static double	get_closest_positive_t(double t1, double t2)
{
	if (t1 > 0 && t2 > 0)
		return (fmin(t1, t2));
	else if (t1 > 0)
		return (t1);
	else if (t2 > 0)
		return (t2);
	return (1000000000);
}

//put this in another file and library because I also use it in sphere
static int	solve_quadratic(double *coefficients, double *roots)
{
	double	discriminant;

	discriminant = coefficients[1] * coefficients[1]
		- 4.0 * coefficients[0] * coefficients[2];
	if (discriminant < 0)
		return (0);
	roots[0] = (-coefficients[1] - sqrt(discriminant)) / (2.0 * coefficients[0]);
	roots[1] = (-coefficients[1] + sqrt(discriminant)) / (2.0 * coefficients[0]);
	return (1);
}

static double	intersect_cylinder_caps(t_vec3 ray, t_vec3 ray_origin,
		t_cylinder *cylinder)
{
	double	t;
	double	t_min;
	t_vec3	p;
	t_vec3	top_center;
	double	radius;

	//	its a bit strange.	try to use nan instead of a big number to represent unreachable or
	//	too far away.
	t_min = 1000000000;
	radius = cylinder->diameter / 2.0;
	top_center = vec3_add(cylinder->position,
			vec3_scale(cylinder->orientation, cylinder->height));

	//considerate separating top and bottom caps to respect norm
	//	you sould add half of the lenght of the cylinder to its center to get one of the caps. 
	t = vec3_dot_product(vec3_sub(cylinder->position, ray_origin),
			cylinder->orientation) / vec3_dot_product(ray, cylinder->orientation);
	if (t > 0)
	{
		p = vec3_add(ray_origin, vec3_scale(ray, t));
		//	I think that you sould do something on the lines of
		//	geting the position of the ray hit relative to the
		//	cylinder center and then get only the perpendicular component
		//	of that vector to know if the ray is hiting the cap or not.
		if (vec3_distance(p, cylinder->position) <= radius)
			t_min = t;
	}

	t = vec3_dot_product(vec3_sub(top_center, ray_origin),
			cylinder->orientation) / vec3_dot_product(ray, cylinder->orientation);
	if (t > 0 && t < t_min)
	{
		p = vec3_add(ray_origin, vec3_scale(ray, t));
		if (vec3_distance(p, top_center) <= radius)
			t_min = t;
	}
	return (t_min);
}

static double	intersect_cylinder_body(t_vec3 ray, t_vec3 ray_origin,
		t_cylinder *cylinder)
{
	double	coefficients[3];
	double	roots[2];
	t_vec3	oc;
	t_vec3	v;
	double	radius;
	double	t;
	t_vec3	p;
	double	h;

	radius = cylinder->diameter / 2.0;
	oc = vec3_sub(ray_origin, cylinder->position);
	v = cylinder->orientation;

	//maybe put in a function
	coefficients[0] = vec3_dot_product(ray, ray)
		- pow(vec3_dot_product(ray, v), 2);
	coefficients[1] = 2 * (vec3_dot_product(ray, oc)
			- vec3_dot_product(ray, v) * vec3_dot_product(oc, v));
	coefficients[2] = vec3_dot_product(oc, oc)
		- pow(vec3_dot_product(oc, v), 2) - radius * radius;

	if (!solve_quadratic(coefficients, roots))
		//	try to use nan
		return (1000000000);

	t = get_closest_positive_t(roots[0], roots[1]);
	if (t >= 1000000000)
		return (t);

	p = vec3_add(ray_origin, vec3_scale(ray, t));
	h = vec3_dot_product(vec3_sub(p, cylinder->position), v);
	if (h < 0 || h > cylinder->height)
		return (1000000000);

	return (t);
}

//	why do you have a ray_origin. the origin of the ray is always on the center or 0, 0, 0.
//	I belive that w
t_ray	ray_cast_cylinder(t_vec3 ray, t_vec3 ray_origin, t_cylinder *cylinder)
{
	t_ray	ray_cast;
	double	t_body;
	double	t_caps;
	double	t;

	t_body = intersect_cylinder_body(ray, ray_origin, cylinder);
	t_caps = intersect_cylinder_caps(ray, ray_origin, cylinder);

	t = get_closest_positive_t(t_body, t_caps);
	ray_cast.magnitude = t;
	ray_cast.color = cylinder->color;

	return (ray_cast);
}
