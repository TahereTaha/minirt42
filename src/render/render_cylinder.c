/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:01:14 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/20 11:25:25 by tatahere         ###   ########.fr       */
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
	return (nan(""));
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

static double	intersect_bottom_cap(t_vec3 ray, t_vec3 origin, t_cylinder *cylinder, double radius)
{
	double	t;
	t_vec3	p;
	t_vec3	hit_relative;
	t_vec3	pos;

	pos = vec3_sub(cylinder->position, origin);
	t = vec3_dot_product(pos,
			cylinder->orientation) / vec3_dot_product(ray, cylinder->orientation);
	if (t <= 0)
		return (nan(""));

	p = vec3_scale(ray, t);
	hit_relative = vec3_sub(p, pos);
	// Get perpendicular component to check if hit is within cap radius
	hit_relative = vec3_sub(hit_relative,
		vec3_scale(cylinder->orientation,
		vec3_dot_product(hit_relative, cylinder->orientation)));

	if (vec3_get_magnitude(hit_relative) <= radius)
		return (t);
	return (nan(""));
}

static double	intersect_top_cap(t_vec3 ray, t_vec3 origin, t_cylinder *cylinder, double radius)
{
	double	t;
	t_vec3	p;
	t_vec3	top_center;
	t_vec3	hit_relative;

	top_center = vec3_add(vec3_sub(cylinder->position, origin),
			vec3_scale(cylinder->orientation, cylinder->height));

	t = vec3_dot_product(top_center,
			cylinder->orientation) / vec3_dot_product(ray, cylinder->orientation);
	if (t <= 0)
		return (nan(""));

	p = vec3_scale(ray, t);
	hit_relative = vec3_sub(p, top_center);
	// Get perpendicular component to check if hit is within cap radius
	hit_relative = vec3_sub(hit_relative,
		vec3_scale(cylinder->orientation,
		vec3_dot_product(hit_relative, cylinder->orientation)));

	if (vec3_get_magnitude(hit_relative) <= radius)
		return (t);
	return (nan(""));
}

static double	intersect_cylinder_caps(t_vec3 ray, t_vec3 origin, t_cylinder *cylinder)
{
	double	t_bottom;
	double	t_top;
	double	radius;

	radius = cylinder->diameter / 2.0;
	t_bottom = intersect_bottom_cap(ray, origin, cylinder, radius);
	t_top = intersect_top_cap(ray, origin, cylinder, radius);

	return (get_closest_positive_t(t_bottom, t_top));
}

static double	intersect_cylinder_body(t_vec3 ray, t_vec3 origin, t_cylinder *cylinder)
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
	oc = vec3_sub(origin, cylinder->position);
	v = cylinder->orientation;

	//maybe put in a function
	coefficients[0] = vec3_dot_product(ray, ray)
		- pow(vec3_dot_product(ray, v), 2);
	coefficients[1] = 2 * (vec3_dot_product(ray, oc)
			- vec3_dot_product(ray, v) * vec3_dot_product(oc, v));
	coefficients[2] = vec3_dot_product(oc, oc)
		- pow(vec3_dot_product(oc, v), 2) - radius * radius;

	if (!solve_quadratic(coefficients, roots))
		return (nan(""));

	t = get_closest_positive_t(roots[0], roots[1]);
	if (isnan(t))
		return (t);

	p = vec3_scale(ray, t);
	h = vec3_dot_product(vec3_sub(p, vec3_sub(cylinder->position, origin)), v);
	if (h < 0 || h > cylinder->height)
		return (nan(""));

	return (t);
}

static t_vec3	get_cylinder_normal(t_vec3 ray, t_vec3 origin, t_cylinder *cylinder, double t)
{
	t_vec3	hit_point;
	t_vec3	hit_relative;
	t_vec3	normal;
	double	proj;

	hit_point = vec3_scale(ray, t);
	hit_relative = vec3_sub(hit_point, vec3_sub(cylinder->position, origin));
	proj = vec3_dot_product(hit_relative, cylinder->orientation);
	if (proj <= 0)
		normal = vec3_scale(cylinder->orientation, -1);
	else if (proj >= cylinder->height)
		normal = cylinder->orientation;
	else
	{
		t_vec3 proj_point;
		proj_point = vec3_scale(cylinder->orientation, proj);
		normal = vec3_normalize(vec3_sub(hit_relative, proj_point));
	}
	return (normal);
}

t_ray	ray_cast_cylinder(t_vec3 ray, t_vec3 origin, t_cylinder *cylinder)
{
	t_ray	ray_cast;
	double	t_body;
	double	t_caps;
	double	t;

	t_body = intersect_cylinder_body(ray, origin, cylinder);
	t_caps = intersect_cylinder_caps(ray, origin, cylinder);

	t = get_closest_positive_t(t_body, t_caps);
	ray_cast.magnitude = t;
	ray_cast.color = cylinder->color;

	if (!isnan(t)) //if it hits 
		ray_cast.normal = get_cylinder_normal(ray, origin, cylinder, t);

	return (ray_cast);
}
