/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_object_list_add.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:57:17 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/19 11:58:29 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "libft.h"
#include "ft_list.h"
#include "error_managment.h"
#include "scene.h"

void	scene_object_list_add(t_error *error, t_scene *scene, t_object object)
{
	t_list		*node;
	t_object	*object_ptr;

	object_ptr = ft_calloc(sizeof(t_object), 1);
	if (!object_ptr)
	{
		error_set(error, errno);
		return ;
	}
	node = ft_lstnew(object_ptr);
	if (!node)
	{
		free(object_ptr);
		error_set(error, errno);
		return ;
	}
	ft_lstadd_back(&scene->objects, node);
}
