/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:33:27 by rgiambon          #+#    #+#             */
/*   Updated: 2025/03/21 10:59:54 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "scene.h"
#include "renderer.h"
#include "vector_math.h"

double	get_closest_positive_t(double t1, double t2)
{
	if (t1 > 0 && t2 > 0)
		return (fmin(t1, t2));
	else if (t1 > 0)
		return (t1);
	else if (t2 > 0)
		return (t2);
	return (nan(""));
}

double	intersect_bottom_cap(t_vec3 ray, t_vec3 origin, \
t_cylinder *cylinder, double radius)
{
	double	t;
	t_vec3	p;
	t_vec3	hit_relative;
	t_vec3	pos;

	pos = vec3_sub(cylinder->position, origin);
	t = vec3_dot_product(pos, cylinder->orientation) \
	/ vec3_dot_product(ray, cylinder->orientation);
	if (t <= 0)
		return (nan(""));
	p = vec3_scale(ray, t);
	hit_relative = vec3_sub(p, pos);
	hit_relative = vec3_sub(hit_relative, vec3_scale(cylinder->orientation, \
	vec3_dot_product(hit_relative, cylinder->orientation)));
	if (vec3_get_magnitude(hit_relative) <= radius)
		return (t);
	return (nan(""));
}

double	intersect_top_cap(t_vec3 ray, t_vec3 origin, \
t_cylinder *cylinder, double radius)
{
	double	t;
	t_vec3	p;
	t_vec3	top_center;
	t_vec3	hit_relative;

	top_center = vec3_add(vec3_sub(cylinder->position, origin),
			vec3_scale(cylinder->orientation, cylinder->height));
	t = vec3_dot_product(top_center, cylinder->orientation) \
	/ vec3_dot_product(ray, cylinder->orientation);
	if (t <= 0)
		return (nan(""));
	p = vec3_scale(ray, t);
	hit_relative = vec3_sub(p, top_center);
	hit_relative = vec3_sub(hit_relative, vec3_scale(cylinder->orientation, \
	vec3_dot_product(hit_relative, cylinder->orientation)));
	if (vec3_get_magnitude(hit_relative) <= radius)
		return (t);
	return (nan(""));
}
