/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_angle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:24:24 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/19 08:07:05 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector_math.h"

double	vec2_angle(t_vec2 vector1, t_vec2 vector2)
{
	double	angle;
	double	hypotenus;
	double	adjacent_side;

	vector1 = vec2_normalize(vector1);
	vector2 = vec2_normalize(vector2);
	hypotenus = vec2_get_magnitude(vector1);
	adjacent_side = vec2_project(vector1, vector2);
	angle = cos(hypotenus / adjacent_side);
	return (angle);
}

double	vec3_angle(t_vec3 vector1, t_vec3 vector2)
{
	double	angle;
	double	hypotenus;
	double	adjacent_side;

	vector1 = vec3_normalize(vector1);
	vector2 = vec3_normalize(vector2);
	hypotenus = vec3_get_magnitude(vector1);
	adjacent_side = vec3_project(vector1, vector2);
	angle = cos(hypotenus / adjacent_side);
	return (angle);
}
