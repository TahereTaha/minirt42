/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:13:08 by rgiambon          #+#    #+#             */
/*   Updated: 2025/04/02 14:13:37 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "scene.h"
#include "renderer.h"

static double	intersect_cone_base(t_vec3 ray, t_vec3 origin, t_cone *cone)
{
	t_vec3	base_center;
	t_vec3	p;
	double	t;
	double	radius;

	base_center = cone->position;
	t = vec3_dot_product(vec3_sub(base_center, origin), cone->orientation)
		/ vec3_dot_product(ray, cone->orientation);
	if (t <= 0)
		return (nan(""));
	p = vec3_add(origin, vec3_scale(ray, t));
	radius = cone->diameter / 2.0;
	if (vec3_get_magnitude(vec3_sub(p, base_center)) > radius)
		return (nan(""));
	return (t);
}

static void	get_cone_coefficients(double coefficients[3], t_vec3 ray,
	t_vec3 origin, t_cone *cone)
{
	t_vec3	oc;
	t_vec3	v;
	double	radius;
	double	k;

	radius = cone->diameter / 2.0;
	k = radius / cone->height;
	oc = vec3_sub(origin, cone->position);
	v = cone->orientation;
	coefficients[0] = vec3_dot_product(ray, ray)
		- (1 + k * k) * pow(vec3_dot_product(ray, v), 2);
	coefficients[1] = 2 * (vec3_dot_product(ray, oc)
			- (1 + k * k) * vec3_dot_product(ray, v) * vec3_dot_product(oc, v));
	coefficients[2] = vec3_dot_product(oc, oc)
		- (1 + k * k) * pow(vec3_dot_product(oc, v), 2);
}

static double	intersect_cone_surface(t_vec3 ray,
	t_vec3 origin, t_cone *cone)
{
	double	coefficients[3];
	double	roots[2];
	double	t;
	t_vec3	p;
	double	h;

	get_cone_coefficients(coefficients, ray, origin, cone);
	if (!solve_quadratic(coefficients, roots))
		return (nan(""));
	t = get_closest_positive_t(roots[0], roots[1]);
	if (isnan(t))
		return (t);
	p = vec3_add(origin, vec3_scale(ray, t));
	h = vec3_dot_product(vec3_sub(p, cone->position), cone->orientation);
	if (h < 0 || h > cone->height)
		return (nan(""));
	return (t);
}

static t_vec3	get_cone_normal(t_vec3 ray, t_vec3 origin,
	t_cone *cone, double t)
{
	t_vec3	hit_point;
	t_vec3	hit_relative;
	t_vec3	axis_point;
	t_vec3	normal;
	double	h;

	hit_point = vec3_add(origin, vec3_scale(ray, t));
	hit_relative = vec3_sub(hit_point, cone->position);
	h = vec3_dot_product(hit_relative, cone->orientation);
	if (h <= 0)
		return (vec3_scale(cone->orientation, -1));
	axis_point = vec3_add(cone->position,
			vec3_scale(cone->orientation, h));

	normal = vec3_normalize(vec3_sub(hit_point, axis_point));
	return (normal);
}

t_ray	ray_cast_cone(t_vec3 ray, t_vec3 origin, t_cone *cone)
{
	t_ray	ray_cast;
	double	t_surface;
	double	t_base;
	double	t;
	t_cone	cone_aux;
	t_vec3	vec;

	cone_aux = *cone;
	vec = vec3_scale(cone_aux.orientation, cone_aux.height);
	cone_aux.position = vec3_add(cone_aux.position, vec);
	cone_aux.orientation = vec3_scale(cone_aux.orientation, -1);
	t_surface = intersect_cone_surface(ray, origin, &cone_aux);
	t_base = intersect_cone_base(ray, origin, cone);
	t = get_closest_positive_t(t_surface, t_base);
	if (isnan(t))
	{
		ray_cast.hit = (t_vec3){0, 0, 0};
		ray_cast.magnitude = INFINITY;
		return (ray_cast);
	}
	ray_cast.hit = vec3_add(origin, vec3_scale(ray, t));
	ray_cast.magnitude = t;
	ray_cast.normal = vec3_scale(get_cone_normal(ray, origin, cone, t), -1);
	ray_cast.color = cone->color;
	return (ray_cast);
}

//static double	intersect_cone_base(t_vec3 ray, t_vec3 origin, t_cone *cone, double radius)
//{
//	double	t;
//	double	radius;
//
//	base_center = cone_aux.position;
//	t = vec3_dot_product(vec3_sub(base_center, origin), cone_aux.orientation)
//		/ vec3_dot_product(ray, cone_aux.orientation);
//	if (t <= 0)
//		return (nan(""));
//	p = vec3_scale(ray, t);
//	radius = cone_aux.diameter / 2.0;
//	if (vec3_get_magnitude(vec3_sub(p, base_center)) > radius)
//		return (nan(""));
//	return (t);
//}
/*
static void	get_cone_coefficients(double coefficients[3], t_vec3 ray,
	t_vec3 origin, t_cone *cone)
{
	t_vec3	oc;
	t_vec3	v;
	double	radius;
	double	k;

	radius = cone_aux.diameter / 2.0;
	k = radius / cone_aux.height;
	oc = vec3_sub(origin, cone_aux.position);
	v = cone_aux.orientation;
	coefficients[0] = vec3_dot_product(ray, ray)
		- (1 + k * k) * pow(vec3_dot_product(ray, v), 2);
	coefficients[1] = 2 * (vec3_dot_product(ray, oc)
			- (1 + k * k) * vec3_dot_product(ray, v) * vec3_dot_product(oc, v));
	coefficients[2] = vec3_dot_product(oc, oc)
		- (1 + k * k) * pow(vec3_dot_product(oc, v), 2);
}

static double	intersect_cone_surface(t_vec3 ray,
	t_vec3 origin, t_cone *cone)
{
	double	coefficients[3];
	double	roots[2];
	double	t;
	t_vec3	p;
	double	h;

	get_cone_coefficients(coefficients, ray, origin, cone);
	if (!solve_quadratic(coefficients, roots))
		return (nan(""));
	t = get_closest_positive_t(roots[0], roots[1]);
	if (isnan(t))
		return (t);
	p = vec3_add(origin, vec3_scale(ray, t));
	h = vec3_dot_product(vec3_sub(p, cone_aux.position), cone_aux.orientation);
	if (h < 0 || h > cone_aux.height)
		return (nan(""));
	return (t);
}
*/
/*
static t_vec3	get_cone_normal(t_vec3 ray, t_vec3 origin,
	t_cone *cone, double t)
{
	t_vec3	hit_point;
	t_vec3	hit_relative;
	t_vec3	normal;
	double	h;
	double	radius;
	double	k;

	hit_point = vec3_add(origin, vec3_scale(ray, t));
	hit_relative = vec3_sub(hit_point, cone_aux.position);
	h = vec3_dot_product(hit_relative, cone_aux.orientation);
	if (h <= 0)
		normal = vec3_scale(cone_aux.orientation, -1);
	else
	{
		radius = (cone_aux.diameter / 2.0) * (1 - h / cone_aux.height);
		k = radius / h;
		normal = vec3_normalize(vec3_sub(hit_relative,
					vec3_scale(cone_aux.orientation, h * (1 + k * k))));
	}
	return (normal);
}*/
/*
#include <stdio.h>

t_ray	ray_cast_cone(t_vec3 ray, t_vec3 origin, t_cone cone_aux)
{
	double	delta_ray;
	double	radius;
	double	cone_aux_distance;
	t_ray	ray_cast;
	t_vec3	hit;
	t_vec3	vec;

	radius = cone_aux.diameter / 2;
	cone_aux.orientation = vec3_scale(cone_aux.orientation, -1);
	cone_aux.position = vec3_sub(cone_aux.position, origin);
	delta_ray = vec3_project(cone_aux.orientation, ray);
	cone_aux_distance = vec3_project(cone_aux.orientation, cone_aux.position);
	ray_cast.magnitude = nan("");
	if (cone_aux_distance == 0.0)
		return (ray_cast);
	ray_cast.magnitude = cone_aux_distance / delta_ray;
	if (ray_cast.magnitude < 0 || delta_ray < 0)
	{
		ray_cast.magnitude = nan("");
		return (ray_cast);
	}
	ray_cast.normal = vec3_scale(cone_aux.orientation, -1);
	ray_cast.color = cone_aux.color;
	hit = vec3_scale(ray, ray_cast.magnitude);
	vec = vec3_sub(hit, cone_aux.position);
	(void)radius;
	(void)vec;
	if (vec3_get_magnitude(vec) > radius)
	{
		printf("the distance is: %f\n", vec3_get_magnitude(vec));
		ray_cast.magnitude = nan("");
	}
	return (ray_cast);
}
*/
