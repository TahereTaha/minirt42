/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_propertis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:16:42 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/22 18:41:27 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_math.h"

int	vec2_is_null(t_vec2 vector)
{
	if (vector.x == 0 && vector.y == 0)
		return (1);
	return (0);
}

int	vec3_is_null(t_vec3 vector)
{
	if (vector.x == 0 && vector.y == 0 && vector.z == 0)
		return (1);
	return (0);
}

int		vec2_is_equal(t_vec2 vector1, t_vec2 vector2)
{
	int	x_equal;
	int	y_equal;

	x_equal = 0;
	if (vector1.x == vector2.x)
		x_equal = 1;
	y_equal = 0;
	if (vector1.y == vector2.y)
		y_equal = 1;
	if (x_equal && y_equal)
		return (1);
	return (0);
}

int		vec3_is_equal(t_vec3 vector1, t_vec3 vector2)
{
	int	x_equal;
	int	y_equal;
	int	z_equal;

	x_equal = 0;
	if (vector1.x == vector2.x)
		x_equal = 1;
	y_equal = 0;
	if (vector1.y == vector2.y)
		y_equal = 1;
	z_equal = 0;
	if (vector1.z == vector2.z)
		z_equal = 1;
	if (x_equal && y_equal && z_equal)
		return (1);
	return (0);
}
