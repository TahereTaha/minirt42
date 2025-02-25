/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_dot_product.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:39:14 by rgiambon          #+#    #+#             */
/*   Updated: 2025/02/25 21:06:41 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vector_math.h"

double	vec2_dot_product(t_vec2 projector, t_vec2 projected)

{
	double	result;
	
	result = projector.x * projected.x + projector.y * projected.y;
    return (result);
}

//	too lazy to change the names here.
double	vec3_dot_product(t_vec3 a, t_vec3 b)
{
	double	result;

	result = a.x * b.x + a.y * b.y + a.z * b.z;
	return (result);
}
