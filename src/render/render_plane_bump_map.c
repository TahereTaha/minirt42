/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_plane_bump_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:58:36 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/08 09:31:51 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "scene.h"
#include "renderer.h"
#include "ft_list.h"
#include "vector_math.h"
#include "parsing.h"
#include "MLX42/MLX42.h"

t_vec3	get_normal(t_bump_map bump_map, t_vec3 ray_hit)
{
	int				y;
	int				x;
	float			width;
	float			height;
	mlx_texture_t	texture;

	texture = *bump_map.texture;
	height = bump_map.height;
	width = bump_map.width;
	y = fmod(fabs(ray_hit.y), height) / height * texture.height;
	x = fmod(fabs(ray_hit.z), width) / width * texture.width;
	ray_hit.x = -((float) texture.pixels[4 * (x + y * texture.width) + 2]) / 256.0;
	ray_hit.y = ((float) texture.pixels[4 * (x + y * texture.width) + 0]) / 256.0;
	ray_hit.z = ((float) texture.pixels[4 * (x + y * texture.width) + 1]) / 256.0;
	ray_hit = vec3_normalize(ray_hit);
//	vec3_print(ray_hit);
	return (ray_hit);
}


t_vec3	rotate_ray_hit(t_vec3 direction, t_bump_map bump_map, t_vec3 ray)
{
	t_mtx3	rotation_matrix_1;
	t_mtx3	rotation_matrix_2;
	t_mtx3	rotation_matrix_3;
	t_mtx3	rotation_matrix_4;
	t_vec3	normal;

	rotation_matrix_1 = make_rotation_mtx_z(direction);
	rotation_matrix_3 = make_a_rotation_mtx_z(direction);
	direction = vec3_mtx3_multiplication(direction, rotation_matrix_1);
	ray = vec3_mtx3_multiplication(ray, rotation_matrix_1);
	rotation_matrix_2 = make_rotation_mtx_y(direction);
	rotation_matrix_4 = make_a_rotation_mtx_y(direction);
	direction = vec3_mtx3_multiplication(direction, rotation_matrix_2);
	ray = vec3_mtx3_multiplication(ray, rotation_matrix_2);
	normal = get_normal(bump_map, ray);
	normal = vec3_mtx3_multiplication(normal, rotation_matrix_4);
	normal = vec3_mtx3_multiplication(normal, rotation_matrix_3);
	return (normal);
}

t_vec3	is_plane_bump_map(t_vec3 ray_hit, t_plane plane)
{
	if (!plane.bump_map.on)
		return (vec3_scale(plane.orientation, -1));
	return (rotate_ray_hit(plane.orientation, plane.bump_map, ray_hit));
}

