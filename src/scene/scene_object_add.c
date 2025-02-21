/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_object_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:54:47 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/20 15:50:00 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_errors.h"
#include "error_managment.h"
#include "scene.h"
#include "scene_local.h"

//	sometimes the 80 whide lines is a hasle.
void	scene_ambient_light_add(t_error *error, t_scene *scene, t_object object)
{
	t_ambient_light	ambient_light;

	ambient_light = *((t_ambient_light *)&object);
	if (scene->ambient_light.kind != BLANK)
	{
		error_set(error, DUPLICATED_OBJECT);
		error_msg_append(error, "ambient ligth: ", 0);
		return ;
	}
	scene->ambient_light = ambient_light;
}

void	scene_camera_add(t_error *error, t_scene *scene, t_object object)
{
	t_camera	camera;

	camera = *((t_camera *)&object);
	if (scene->camera.kind != BLANK)
	{
		error_set(error, DUPLICATED_OBJECT);
		error_msg_append(error, "camera: ", 0);
		return ;
	}
	scene->camera = camera;
}

void	scene_light_add(t_error *error, t_scene *scene, t_object object)
{
	t_light	light;

	light = *((t_light *)&object);
	if (scene->light.kind != BLANK)
	{
		error_set(error, DUPLICATED_OBJECT);
		error_msg_append(error, "ligth: ", 0);
		return ;
	}
	scene->light = light;
}

void	scene_object_add(t_error *error, t_scene *scene, t_object object)
{
	g_add_object[object.kind - AMBIENT_LIGHT](error, scene, object);
}
