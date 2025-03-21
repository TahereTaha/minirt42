/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_local.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:08:54 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/21 10:40:04 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_LOCAL_H
# define SCENE_LOCAL_H

# include <stdlib.h>
# include "error_managment.h"

void	scene_ambient_light_add(t_error *err, t_scene *scene, t_object obj);
void	scene_camera_add(t_error *error, t_scene *scene, t_object object);
void	scene_light_add(t_error *error, t_scene *scene, t_object object);

typedef void				(*t_add_object)(t_error *, t_scene *, t_object);

static const t_add_object	g_add_object[] = \
	{\
	(t_add_object) scene_ambient_light_add, \
	(t_add_object) scene_camera_add, \
	(t_add_object) scene_light_add, \
	(t_add_object) NULL \
};

#endif
