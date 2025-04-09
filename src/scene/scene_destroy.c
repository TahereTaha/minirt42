/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:28:33 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/09 09:34:48 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "error_managment.h"
#include "libft.h"
#include "ft_list.h"
#include "scene.h"

void	free_map(t_object *object)
{
	t_plane	*plane;

	if (object->kind != PLANE)
		return ;
	plane = (t_plane *)object;
	if (plane->bump_map.texture)
		mlx_delete_texture(plane->bump_map.texture);
}

void	free_all_maps(t_list *objects)
{
	t_list	*node;

	node = objects;
	while (node)
	{
		free_map(node->content);
		node = node->next;
	}
}

void	scene_destroy(t_scene *scene)
{
	free_all_maps(scene->objects);
	ft_lstclear(&scene->objects, (t_del) free);
	ft_lstclear(&scene->lights, (t_del) free);
	free(scene);
}
