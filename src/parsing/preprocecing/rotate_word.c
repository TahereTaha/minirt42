/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:57:02 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/20 13:26:07 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector_math.h"
#include "parsing.h"
#include "scene.h"

t_mtx3	unit_vector(void)
{
	t_mtx3	mtx;

	mtx.i_hat.x = 1;
	mtx.i_hat.y = 0;
	mtx.i_hat.z = 0;
	mtx.j_hat.x = 0;
	mtx.j_hat.y = 1;
	mtx.j_hat.z = 0;
	mtx.k_hat.x = 0;
	mtx.k_hat.y = 0;
	mtx.k_hat.z = 1;
	return (mtx);
}

t_mtx3	make_rotation_mtx_z(t_vec3 direction)
{
	t_mtx3	mtx;

	if (direction.y == 0)
		return (unit_vector());
	direction.z = 0;
	direction = vec3_normalize(direction);
	mtx.i_hat.x = direction.x;
	mtx.i_hat.y = -direction.y;
	mtx.i_hat.z = 0;
	mtx.j_hat.x = direction.y;
	mtx.j_hat.y = direction.x;
	mtx.j_hat.z = 0;
	mtx.k_hat.x = 0;
	mtx.k_hat.y = 0;
	mtx.k_hat.z = 1;
	return (mtx);
}

t_mtx3	make_rotation_mtx_y(t_vec3 direction)
{
	t_mtx3	mtx;

	if (direction.z == 0)
		return (unit_vector());
	mtx.i_hat.x = direction.x;
	mtx.i_hat.y = 0;
	mtx.i_hat.z = -direction.z;
	mtx.j_hat.x = 0;
	mtx.j_hat.y = 1;
	mtx.j_hat.z = 0;
	mtx.k_hat.x = direction.z;
	mtx.k_hat.y = 0;
	mtx.k_hat.z = direction.x;
	return (mtx);
}

void	rotate_sphere(t_sphere *object, t_mtx3 mtx)
{
	t_vec3	vec;

	vec = object->position;
	object->position = vec3_mtx3_multiplication(vec, mtx);
}

void	rotate_plane(t_plane *object, t_mtx3 mtx)
{
	t_vec3	vec;

	vec = object->position;
	object->position = vec3_mtx3_multiplication(vec, mtx);
	vec = object->orientation;
	object->orientation = vec3_mtx3_multiplication(vec, mtx);
}
