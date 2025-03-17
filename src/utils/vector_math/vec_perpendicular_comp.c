/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_perpendicular_comp.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:55:22 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/16 18:04:18 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_math.h"

t_vec2	vec2_perp_comp(t_vec2 reference, t_vec2 vector)
{
	t_vec2	paralel_comp;
	t_vec2	perpendicular_comp;

	paralel_comp = vec2_paral_comp(reference, vector);
	penpendicular_comp = vec2_sub(vector, paralel_comp);
	return (perpendicular_comp);
}

t_vec3	vec3_perp_comp(t_vec3 reference, t_vec3 vector)
{
	t_vec3	paralel_comp;
	t_vec3	perpendicular_comp;

	paralel_comp = vec3_paral_comp(reference, vector);
	penpendicular_comp = vec3_sub(vector, paralel_comp);
	return (perpendicular_comp);
}
