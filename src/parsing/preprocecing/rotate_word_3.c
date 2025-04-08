/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_word_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:26:47 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/08 08:56:04 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector_math.h"
#include "parsing.h"
#include "scene.h"

t_mtx3	make_a_rotation_mtx_z(t_vec3 direction)
{
	t_mtx3	mtx;

	if (direction.y == 0)
		return (unit_vector());
	direction.z = 0;
	direction = vec3_normalize(direction);
	mtx.i_hat.x = direction.x;
	mtx.i_hat.y = direction.y;
	mtx.i_hat.z = 0;
	mtx.j_hat.x = -direction.y;
	mtx.j_hat.y = direction.x;
	mtx.j_hat.z = 0;
	mtx.k_hat.x = 0;
	mtx.k_hat.y = 0;
	mtx.k_hat.z = 1;
	return (mtx);
}

t_mtx3	make_a_rotation_mtx_y(t_vec3 direction)
{
	t_mtx3	mtx;

	if (direction.z == 0)
		return (unit_vector());
	mtx.i_hat.x = direction.x;
	mtx.i_hat.y = 0;
	mtx.i_hat.z = direction.z;
	mtx.j_hat.x = 0;
	mtx.j_hat.y = 1;
	mtx.j_hat.z = 0;
	mtx.k_hat.x = -direction.z;
	mtx.k_hat.y = 0;
	mtx.k_hat.z = direction.x;
	return (mtx);
}

