/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:09:58 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/25 10:09:58 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_math.h"
#include <math.h>

t_vec2	vec2_rotate(t_vec2 vector, double angle)
{
	t_vec2	new_vector;
	double	cos_a;
	double	sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	new_vector.x = vector.x * cos_a - vector.y * sin_a;
	new_vector.y = vector.x * sin_a + vector.y * cos_a;
	return (new_vector);
}

t_vec3	vec3_rotate_x(t_vec3 vector, double angle)
{
	t_vec3	new_vector;
	double	cos_a;
	double	sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	new_vector.x = vector.x;
	new_vector.y = vector.y * cos_a - vector.z * sin_a;
	new_vector.z = vector.y * sin_a + vector.z * cos_a;
	return (new_vector);
}

t_vec3	vec3_rotate_y(t_vec3 vector, double angle)
{
	t_vec3	new_vector;
	double	cos_a;
	double	sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	new_vector.x = vector.x * cos_a + vector.z * sin_a;
	new_vector.y = vector.y;
	new_vector.z = -vector.x * sin_a + vector.z * cos_a;
	return (new_vector);
}

t_vec3	vec3_rotate_z(t_vec3 vector, double angle)
{
	t_vec3	new_vector;
	double	cos_a;
	double	sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	new_vector.x = vector.x * cos_a - vector.y * sin_a;
	new_vector.y = vector.x * sin_a + vector.y * cos_a;
	new_vector.z = vector.z;
	return (new_vector);
}
