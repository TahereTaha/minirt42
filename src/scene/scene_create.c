/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:10:47 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/21 10:35:54 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene.h"

t_scene	*scene_create(void)
{
	t_scene	*scene;

	scene = ft_calloc(sizeof(t_scene), 1);
	return (scene);
}
