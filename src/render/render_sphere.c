/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:23:11 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/18 05:52:43 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "scene.h"
#include "renderer.h"
#include "vector_math.h"

void	get_sphere_coefficients(t_vec3 ray, t_vec3 oc, double radius,
		double *coefficients)
{
	coefficients[0] = vec3_dot_product(ray, ray);
	coefficients[1] = 2.0 * vec3_dot_product(ray, oc);
	coefficients[2] = vec3_dot_product(oc, oc) - (radius * radius);
}

double	get_closest_intersection(double t1, double t2)
{
	if (t1 > 0 && t2 > 0)
		return (fmin(t1, t2));
	else if (t1 > 0)
		return (t1);
	else if (t2 > 0)
		return (t2);
	return (nan(""));
}

// consider to put this function in some other file 
int	solve_quadratic(double *coefficients, double *roots)
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

t_ray	ray_cast_sphere(t_vec3 ray, t_vec3 origin, t_sphere sphere)
{
	t_ray	ray_cast;
	//	what is oc?
	t_vec3	oc;
	double	coefficients[3];
	double	roots[2];
	t_vec3	hit_point;
//	double	radius;	// needed to remove one variable.

	sphere.position = vec3_sub(sphere.position, origin);
	oc = vec3_scale(sphere.position, -1);
//	radius = sphere.diameter / 2.0;
	get_sphere_coefficients(ray, oc, sphere.diameter / 2.0 , coefficients);
	ray_cast.color = sphere.color;
	if (!solve_quadratic(coefficients, roots))
	{
		ray_cast.magnitude = nan("");
		return (ray_cast);
	}
	ray_cast.magnitude = get_closest_intersection(roots[0], roots[1]);
	hit_point = vec3_scale(ray, ray_cast.magnitude);
	ray_cast.normal = vec3_sub(hit_point, sphere.position);
	ray_cast.normal = vec3_normalize(ray_cast.normal);
	return (ray_cast);
}
