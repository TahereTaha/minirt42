/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_paralel_comp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:40:08 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/16 18:02:14 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_math.h"

t_vec2	vec2_paral_comp(t_vec2 reference, t_vec2 vector)
{
	t_vec2	comp;
	double	scalar;

	scalar = vec2_project(reference, vector) / vec2_get_magnitude(vector);
	comp = vec2_scale(reference, scalar);
	return (comp);
}

t_vec3	vec3_paral_comp(t_vec3 reference, t_vec3 vector)
{
	t_vec3	comp;
	double	scalar;

	scalar = vec3_project(reference, vector) / vec3_get_magnitude(vector);
	comp = vec3_scale(reference, scalar);
	return (comp);
}
