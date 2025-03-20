/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 05:59:21 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/20 14:44:07 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "scene.h"
#include "renderer.h"
#include "ft_list.h"

int	is_light_visible(t_light light, t_ray hit_point, t_list *objects)
{
	t_list	*node;
	t_ray	ray_cast;
	t_vec3	ray;

	light.position = vec3_sub(light.position, hit_point.hit);
	ray = vec3_normalize(light.position);
	node = objects;
	while (node)
	{
		ray_cast = ray_cast_object(ray, hit_point.hit, node->content);
		if (!isnan(ray_cast.magnitude) && \
			vec3_get_magnitude(light.position) > ray_cast.magnitude)
			return (0);
		node = node->next;
	}
	return (1);
}

t_color	light_point(t_ray hit_point, t_scene *scene)
{
	t_color	color;
	t_color	light;
	t_color	tmp;

	light = get_ambient_light(scene->ambient_light);
	tmp = get_difuse_light(scene, hit_point);
	light = add_color(light, tmp);
	color = light_color(hit_point.color, light);
	return (color);
}
