/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preproces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:11:23 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/11 12:01:10 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "scene.h"

//	move the camera to the center.
//	normalize everithing. and make the plane normals point the right way.
//	rotate everithing the correct way.

void	preproces(t_scene *scene)
{
	move_camera_to_center(scene);
	normalize_scene(scene);
	rotate_word(scene);
	normalize_scene(scene);
}
