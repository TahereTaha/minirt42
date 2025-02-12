/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_get_magnitude.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 07:36:16 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/12 09:59:02 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector_math.h"

double	vec2_get_magnitude(t_vec2 vector)
{
	return (sqrt(pow(vector.x, 2) + pow(vector.y, 2)));
}

double	vec3_get_magnitude(t_vec3 vector)
{
	return (sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2)));
}
