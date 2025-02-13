/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_scaling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:01:57 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/12 10:42:14 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_math.h"

t_vec2	vec2_scale(t_vec2 vector, double scalar)
{
	t_vec2	new_vector;

	new_vector.x = vector.x * scalar;
	new_vector.y = vector.y * scalar;
	return (new_vector);
}

t_vec3	vec3_scale(t_vec3 vector, double scalar)
{
	t_vec3	new_vector;

	new_vector.x = vector.x * scalar;
	new_vector.y = vector.y * scalar;
	new_vector.z = vector.z * scalar;
	return (new_vector);
}
