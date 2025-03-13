/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:45:34 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/13 20:54:44 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_list.h"
#include "scene.h"

t_object	*copy_object(t_object *object)
{
	t_object	*new_object;

	new_object = ft_calloc(sizeof(t_object), 1);
	if (!new_object)
		return (NULL);
	*new_object = *object;
	return (new_object);
}

t_scene	*scene_copy_constructor(t_scene *target)
{
	t_scene	*new_scene;
	t_list	*list;

	new_scene = scene_create();
	if (!new_scene)
		return (NULL);
	*new_scene = *target;
	list = ft_lstmap(target->objects, (t_map) copy_object, (t_del) free);
	if (!list)
	{
		free(new_scene);
		return (NULL);
	}
	new_scene->objects = list;
	return (new_scene);
}

void	copy_object_list(t_list *target, t_list *dest)
{
	t_object	*target_object;
	t_object	*dest_object;

	while (target)
	{
		target_object = target->content;
		dest_object = dest->content;
		*dest_object = *target_object;
		dest = dest->next;
		target = target->next;
	}
}

void	scene_copy_assigment(t_scene *target, t_scene *dest)
{
	t_list	*tmp;

	tmp = dest->objects;
	*dest = *target;
	dest->objects = tmp;
	copy_object_list(target->objects, dest->objects);
	return ;
}
