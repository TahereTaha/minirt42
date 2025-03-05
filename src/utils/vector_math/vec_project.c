/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_project.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:27:37 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/05 17:39:03 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_math.h"

double	vec2_project(t_vec2 projector, t_vec2 projected)
{
	double	dot_product;
	double	projection_magnitude;

	dot_product = vec2_dot_product(projector, projected);
	projection_magnitude = dot_product / vec2_get_magnitude(projector);
	return (projection_magnitude);
}

double	vec3_project(t_vec3 projector, t_vec3 projected)
{
	double	dot_product;
	double	projection_magnitude;

	dot_product = vec3_dot_product(projector, projected);
	projection_magnitude = dot_product / vec3_get_magnitude(projector);
	return (projection_magnitude);
}
