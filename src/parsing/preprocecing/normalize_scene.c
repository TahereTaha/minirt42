/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:21:51 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/21 07:39:57 by tatahere         ###   ########.fr       */
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
	num = vec3_project(plane->orientation, plane->position);
	if (num > 0)
		plane->orientation = vec3_scale(plane->orientation, -1);
}

static void	normalize_cylinder(t_cylinder *cylinder)
{
	cylinder->orientation = vec3_normalize(cylinder->orientation);
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
		if (object->kind == CYLINDER)
			normalize_cylinder((t_cylinder *)object);
		node = node->next;
	}
}

void	normalize_scene(t_scene *scene)
{
	if (vec3_is_null(scene->camera.orientation))
		scene->camera.orientation = (t_vec3){1, 0, 0};
	scene->camera.orientation = vec3_normalize(scene->camera.orientation);
	normalize_objects(scene->objects);
}
