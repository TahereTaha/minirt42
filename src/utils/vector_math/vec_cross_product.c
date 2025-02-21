/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_cross_product.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:39:54 by rgiambon          #+#    #+#             */
/*   Updated: 2025/02/21 12:52:19 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_math.h"

double cross_product_2d(t_vec2 a, t_vec2 b)
{
	double	result;

	result = a.x * b.y - a.y * b.x;
    return (result);
}

t_vec3 cross_product(t_vec3 a, t_vec3 b)
{
    t_vec3 result;

    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}
