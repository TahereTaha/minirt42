/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 05:59:21 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/18 06:43:10 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "scene.h"
#include "renderer.h"
#include "ft_list.h"

int		is_light_visible(t_light light, t_ray hit_point, t_list *objects)
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

t_color	light_point(t_ray hit_point, t_light light, t_list *objects)
{
	t_color	color;

	color = (t_color){0, 0, 0};
	if (is_light_visible(light, hit_point, objects))
		color = hit_point.color;
	return (color);
}
