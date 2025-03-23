/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_phong_shine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:17:34 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/23 16:33:04 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "numbers.h"
#include "scene.h"
#include "renderer.h"
#include "ft_list.h"

static	t_vec3	get_reflected_ray(t_ray hit_point)
{
	t_vec3	ray;
	t_vec3	tmp;

	ray = vec3_normalize(hit_point.hit);
	ray = vec3_scale(ray, -1);
	tmp = vec3_perp_comp(hit_point.normal, ray);
	tmp = vec3_scale(tmp, -2);
	ray = vec3_add(ray, tmp);
	return (ray);
}

static	double	get_angle(t_light light, t_ray hit_point)
{
	double	angle;
	t_vec3	reflected_ray;

	light.position = vec3_sub(light.position, hit_point.hit);
	light.position = vec3_normalize(light.position);
	reflected_ray = get_reflected_ray(hit_point);
	angle = fabs(vec3_project(light.position, reflected_ray));
	angle = pow(angle, 30);
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

t_color	get_phong_shine(t_scene *scene, t_ray hit_point)
{
	t_color	light;

	light = get_light_value(scene->light, hit_point, scene->objects);
	return (light);
}
