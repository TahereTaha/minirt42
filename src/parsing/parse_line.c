/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:45:27 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/19 12:13:25 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_managment.h"
#include "scene.h"
#include "parsing.h"

void	add_object_to_scene(t_error *error, t_scene *scene, t_object object)
{
	if (object.kind == BLANK)
		return ;
	if (object.kind >= SPHERE && object.kind <= CYLINDER)
		scene_object_list_add(error, scene, object);
	else
		scene_object_add(error, scene, object);
}

void	parse_line(t_error *error, t_scene *scene, char *line)
{
	t_object	object;

	object = object_create(error, line);
	if (error->errnum)
		return ;
	add_object_to_scene(error, scene, object);
}
