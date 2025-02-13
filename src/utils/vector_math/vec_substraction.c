/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_substraction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:43:21 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/12 10:28:36 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_math.h"

t_vec2	vec2_sub(t_vec2 vector1, t_vec2 vector2)
{
	t_vec2	new_vector;

	new_vector.x = vector1.x - vector2.x;
	new_vector.y = vector1.y - vector2.y;
	return (new_vector);
}

t_vec3	vec3_sub(t_vec3 vector1, t_vec3 vector2)
{
	t_vec3	new_vector;

	new_vector.x = vector1.x - vector2.x;
	new_vector.y = vector1.y - vector2.y;
	new_vector.z = vector1.z - vector2.z;
	return (new_vector);
}
