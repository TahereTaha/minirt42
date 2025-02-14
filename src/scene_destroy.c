/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:28:33 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/14 18:48:00 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "error_managment.h"
#include "libft.h"
#include "ft_list.h"
#include "minirt.h"

void	free_object(t_object *object)
{
	free(object->content);
	free(object);
}

void	scene_destroy(t_scene *scene)
{
	ft_lstclear(&scene->objects, (t_del) free_object);
	free(scene);
}
