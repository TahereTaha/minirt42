/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:47:36 by rgiambon          #+#    #+#             */
/*   Updated: 2025/03/21 10:47:41 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "scene.h"
#include "renderer.h"

static double	intersect_cylinder_caps(t_vec3 ray, t_vec3 origin, \
t_cylinder *cylinder)
{
	double	t_bottom;
	double	t_top;
	double	radius;

	radius = cylinder->diameter / 2.0;
	t_bottom = intersect_bottom_cap(ray, origin, cylinder, radius);
	t_top = intersect_top_cap(ray, origin, cylinder, radius);
	return (get_closest_positive_t(t_bottom, t_top));
}

static void	get_cylinder_coefficients(double coefficients[3], t_vec3 ray, \
t_vec3 origin, t_cylinder *cylinder)
{
	t_vec3	oc;
	t_vec3	v;
	double	radius;

	radius = cylinder->diameter / 2.0;
	oc = vec3_sub(origin, cylinder->position);
	v = cylinder->orientation;
	coefficients[0] = vec3_dot_product(ray, ray) \
	- pow(vec3_dot_product(ray, v), 2);
	coefficients[1] = 2 * (vec3_dot_product(ray, oc)
			- vec3_dot_product(ray, v) * vec3_dot_product(oc, v));
	coefficients[2] = vec3_dot_product(oc, oc) \
	- pow(vec3_dot_product(oc, v), 2) - radius * radius;
}

static double	intersect_cylinder_body(t_vec3 ray, \
t_vec3 origin, t_cylinder *cylinder)
{
	double	coefficients[3];
	double	roots[2];
	double	t;
	t_vec3	p;
	double	h;

	get_cylinder_coefficients(coefficients, ray, origin, cylinder);
	if (!solve_quadratic(coefficients, roots))
		return (nan(""));
	t = get_closest_positive_t(roots[0], roots[1]);
	if (isnan(t))
		return (t);
	p = vec3_scale(ray, t);
	h = vec3_dot_product(vec3_sub(p, vec3_sub(cylinder->position, origin)), \
		cylinder->orientation);
	if (h < 0 || h > cylinder->height)
		return (nan(""));
	return (t);
}

static t_vec3	get_cylinder_normal(t_vec3 ray, \
t_vec3 origin, t_cylinder *cylinder, double t)
{
	t_vec3	hit_point;
	t_vec3	hit_relative;
	t_vec3	normal;
	double	proj;
	t_vec3	proj_point;

	hit_point = vec3_scale(ray, t);
	hit_relative = vec3_sub(hit_point, vec3_sub(cylinder->position, origin));
	proj = vec3_dot_product(hit_relative, cylinder->orientation);
	if (proj <= 0)
		normal = vec3_scale(cylinder->orientation, -1);
	else if (proj >= cylinder->height)
		normal = cylinder->orientation;
	else
	{
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
	if (!isnan(t))
		ray_cast.normal = get_cylinder_normal(ray, origin, cylinder, t);
	return (ray_cast);
}
