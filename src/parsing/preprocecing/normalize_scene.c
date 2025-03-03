/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:21:51 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/28 18:19:26 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "scene.h"
#include "vector_math.h"
#include "ft_list.h"
#include "parsing.h"

static void	normalize_plane(t_plane *plane)
{
	double	num;

	plane->orientation = vec3_normalize(plane->orientation);
	num = vec3_dot_product(plane->orientation, plane->position) / \
		  vec3_get_magnitude(plane->orientation);
	if (num < 0)
	{
		plane->orientation = vec3_scale(plane->orientation, -1);
	}
}

static void	normalize_objects(t_list *objects)
{
	t_list		*node;
	t_object	*object;

	node = objects;
	while (node)
	{
		object = (t_object *)node->content;
		if (object->kind == PLANE)
			normalize_plane((t_plane *)object);
		node = node->next;
	}
}

void	normalize_scene(t_scene *scene)
{
	scene->camera.view_point = vec3_normalize(scene->camera.view_point);
	normalize_objects(scene->objects);
}
