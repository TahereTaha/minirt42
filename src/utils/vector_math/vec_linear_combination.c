/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_linear_combination.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:42:59 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/12 11:05:40 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_math.h"

t_vec2	vec2_linear_combination(	t_vec2 vector1, double scalar1, \
									t_vec2 vector2, double scalar2)
{
	t_vec2	vector1_scaled;
	t_vec2	vector2_scaled;
	t_vec2	new_vector;

	vector1_scaled = vec2_scale(vector1, scalar1);
	vector2_scaled = vec2_scale(vector2, scalar2);
	new_vector = vec2_add(vector1_scaled, vector2_scaled);
	return (new_vector);
}

//	To change the bases of a 3d space do the folloing.
//		- linearly combine 2 of the 3 new basis.
//		- linearly combine the last result with a scalar of 1 and the third basis.
//	This is because of my inability to write good code or the norminet.
//	If you ask me I would say that it is the normiten fault.
//	But most probably it is because of me.
t_vec3	vec3_linear_combination(	t_vec3 vector1, double scalar1, \
									t_vec3 vector2, double scalar2)
{
	t_vec3	vector1_scaled;
	t_vec3	vector2_scaled;
	t_vec3	new_vector;

	vector1_scaled = vec3_scale(vector1, scalar1);
	vector2_scaled = vec3_scale(vector2, scalar2);
	new_vector = vec3_add(vector1_scaled, vector2_scaled);
	return (new_vector);
}
