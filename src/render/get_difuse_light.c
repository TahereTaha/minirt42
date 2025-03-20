/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_difuse_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 05:42:37 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/20 14:46:47 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "numbers.h"
#include "scene.h"
#include "renderer.h"
#include "ft_list.h"

static	double	get_angle(t_light light, t_ray hit_point)
{
	double	angle;

	light.position = vec3_sub(light.position, hit_point.hit);
	light.position = vec3_normalize(light.position);
	hit_point.normal = vec3_normalize(hit_point.normal);
	angle = fabs(vec3_project(light.position, hit_point.normal));
	return (angle);
}

static t_color	get_light_value(t_light light, t_ray hit_point, t_list *objects)
{
	t_color	color;
	double	scalar;

	color = (t_color){0, 0, 0};
	if (!is_light_visible(light, hit_point, objects))
		return (color);
	color = light.light_color;
	color = scale_color(color, light.light_ratio);
	scalar = get_angle(light, hit_point);
	color = scale_color(color, scalar);
	return (color);
}

t_color	get_difuse_light(t_scene *scene, t_ray hit_point)
{
	t_color	light;

	light = get_light_value(scene->light, hit_point, scene->objects);
	return (light);
}
