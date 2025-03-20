/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_word_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:20:48 by rgiambon          #+#    #+#             */
/*   Updated: 2025/03/20 13:25:26 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector_math.h"
#include "parsing.h"
#include "scene.h"

void	rotate_cylinder(t_cylinder *object, t_mtx3 mtx)
{
	t_vec3	vec;

	vec = object->position;
	object->position = vec3_mtx3_multiplication(vec, mtx);
	vec = object->orientation;
	object->orientation = vec3_mtx3_multiplication(vec, mtx);
}

void	transform_all_objects_vectors(t_list *objects, t_mtx3 mtx)
{
	t_list		*node;
	t_object	*object;

	node = objects;
	while (node)
	{
		object = (t_object *)node->content;
		if (object->kind == PLANE)
			rotate_plane((t_plane *)object, mtx);
		if (object->kind == SPHERE)
			rotate_sphere((t_sphere *)object, mtx);
		if (object->kind == CYLINDER)
			rotate_cylinder((t_cylinder *)object, mtx);
		node = node->next;
	}
}

void	transform_all_vectors(t_scene *scene, t_mtx3 mtx)
{
	t_vec3	vec;

	vec = scene->camera.orientation;
	scene->camera.orientation = vec3_mtx3_multiplication(vec, mtx);
	vec = scene->light.position;
	scene->light.position = vec3_mtx3_multiplication(vec, mtx);
	transform_all_objects_vectors(scene->objects, mtx);
}

void	rotate_word(t_scene *scene)
{
	t_mtx3	rotation_matrix;

	rotation_matrix = make_rotation_mtx_z(scene->camera.orientation);
	transform_all_vectors(scene, rotation_matrix);
	rotation_matrix = make_rotation_mtx_y(scene->camera.orientation);
	transform_all_vectors(scene, rotation_matrix);
}
