/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera_to_center.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:31:50 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/26 14:20:54 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "vector_math.h"
#include "scene.h"
#include "parsing.h"

static void	move_sphere(t_sphere *sphere, t_vec3 camera_pos)
{
	sphere->position = vec3_sub(sphere->position, camera_pos);
}

static void	move_plane(t_plane *plane, t_vec3 camera_pos)
{
	plane->position = vec3_sub(plane->position, camera_pos);
}

static void	move_cylinder(t_cylinder *cylinder, t_vec3 camera_pos)
{
	cylinder->position = vec3_sub(cylinder->position, camera_pos);
}

static void	move_objects(t_list *objects, t_vec3 camera_pos)
{
	t_list		*node;
	t_object	*object;

	node = objects;
	while (node)
	{
		object = (t_object *)node->content;
		if (object->kind == PLANE)
			move_plane((t_plane *)object, camera_pos);
		if (object->kind == SPHERE)
			move_sphere((t_sphere *)object, camera_pos);
		if (object->kind == CYLINDER)
			move_cylinder((t_cylinder *)object, camera_pos);
		node = node->next;
	}
}

void	move_camera_to_center(t_scene *scene)
{
	t_vec3	camera_pos;

	camera_pos = scene->camera.view_point;
	scene->light.position = vec3_sub(scene->light.position, camera_pos);
	move_objects(scene->objects, camera_pos);
	scene->camera.view_point = vec3_scale(camera_pos, 0);
}
