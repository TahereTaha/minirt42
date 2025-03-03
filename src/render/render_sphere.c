/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:23:11 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/27 10:23:11 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "scene.h"
#include "renderer.h"

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
	return (1000000000);
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

t_ray	ray_cast_sphere(t_vec3 ray, t_sphere *sphere)
{
	t_ray	ray_cast;
	t_vec3	oc;
	double	coefficients[3];
	double	roots[2];
	double	radius;

	oc = vec3_scale(sphere->position, -1);
	radius = sphere->diameter / 2.0;
	get_sphere_coefficients(ray, oc, radius, coefficients);
	ray_cast.color = sphere->color;
	if (!solve_quadratic(coefficients, roots))
	{
		ray_cast.magnitude = 1000000000;
		return (ray_cast);
	}
	ray_cast.magnitude = get_closest_intersection(roots[0], roots[1]);
	return (ray_cast);
}
