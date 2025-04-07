/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_plane_disrupt.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:58:36 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/06 20:22:25 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "scene.h"
#include "renderer.h"
#include "ft_list.h"
#include "vector_math.h"
#include "parsing.h"

float	ftfabs(float num, float scale)
{
	float	num2;

	num2 = fabs(num);
	if (num < 0)
		num2 += scale;
	return (num2);
}

//	this expect a t_vec3 that has alredy ben rotated.
//	it is really strange but the x and y are fliped.
int	is_disrupted(t_vec3 ray_hit, float width, float height)
{
	int	is_disrupted_z;
	int	is_disrupted_y;

	is_disrupted_y = fmod(ftfabs(ray_hit.y, height), height * 2.0) < height;
	is_disrupted_z = fmod(ftfabs(ray_hit.z, width), width * 2.0) < width;
	if (is_disrupted_z ^ is_disrupted_y)
		return (1);
	return (0);
}

static void	rotate_ray_hit(t_vec3 direction, t_vec3 *ray_hit)
{
	t_mtx3	rotation_matrix;

	rotation_matrix = make_rotation_mtx_z(direction);
	direction = vec3_mtx3_multiplication(direction, rotation_matrix);
	*ray_hit = vec3_mtx3_multiplication(*ray_hit, rotation_matrix);
	rotation_matrix = make_rotation_mtx_y(direction);
	direction = vec3_mtx3_multiplication(direction, rotation_matrix);
	*ray_hit = vec3_mtx3_multiplication(*ray_hit, rotation_matrix);
}

int	is_plane_disrupted(t_vec3 ray_hit, t_plane plane)
{
	if (!plane.disrupt.on)
		return (0);
	rotate_ray_hit(plane.orientation, &ray_hit);
	ray_hit.y -= plane.disrupt.height / 2;
	ray_hit.z -= plane.disrupt.width / 2;
	return (is_disrupted(ray_hit, plane.disrupt.width, plane.disrupt.height));
}

