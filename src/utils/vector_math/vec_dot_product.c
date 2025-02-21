/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_dot_product.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:39:14 by rgiambon          #+#    #+#             */
/*   Updated: 2025/02/21 13:42:40 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vector_math.h"

double	vec2_dot_product(t_vec2 a, t_vec2 b)
{
	double	result;

	result = a.x * b.x + a.y * b.y;
    return (result);
}

double	vec3_dot_product(t_vec3 a, t_vec3 b)
{
	double	result;

	result = a.x * b.x + a.y * b.y + a.z * b.z;
    return (result);
}
