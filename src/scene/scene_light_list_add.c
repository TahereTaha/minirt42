/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_light_list_add.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:52:35 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/23 16:54:53 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "libft.h"
#include "ft_list.h"
#include "error_managment.h"
#include "scene.h"

void	scene_light_list_add(t_error *error, t_scene *scene, t_object object)
{
	t_list		*node;
	t_object	*object_ptr;

	object_ptr = ft_calloc(sizeof(t_object), 1);
	if (!object_ptr)
	{
		error_set(error, errno);
		return ;
	}
	*object_ptr = object;
	node = ft_lstnew(object_ptr);
	if (!node)
	{
		free(object_ptr);
		error_set(error, errno);
		return ;
	}
	ft_lstadd_back(&scene->lights, node);
}
