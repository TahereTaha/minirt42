/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:10:33 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/12 10:19:30 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_math.h"

t_vec2	vec2_normalize(t_vec2 vector)
{
	t_vec2	new_vector;
	double	magnitude;

	if (vec2_is_null(vector))
		return (vector);
	magnitude = vec2_get_magnitude(vector);
	new_vector = vec2_scale(vector, 1 / magnitude);
	return (new_vector);
}

t_vec3	vec3_normalize(t_vec3 vector)
{
	t_vec3	new_vector;
	double	magnitude;

	if (vec3_is_null(vector))
		return (vector);
	magnitude = vec3_get_magnitude(vector);
	new_vector = vec3_scale(vector, 1 / magnitude);
	return (new_vector);
}
