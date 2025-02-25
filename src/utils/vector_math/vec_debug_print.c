/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_debug_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:21:55 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/25 18:07:09 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "vector_math.h"

void	vec2_print(t_vec2 vector)
{
	printf("vec2:x=%.20f,y=%.20f\n", vector.x, vector.y);
}

void	vec2_print_multiline(t_vec2 vector)
{
	printf("vec2:\nx=%.20f\ny=%.20f\n", vector.x, vector.y);
}

void	vec3_print(t_vec3 vector)
{
	printf("vec3:x=%.20f,y=%.20f,z=%.20f\n", vector.x, vector.y, vector.z);
}

void	vec3_print_multiline(t_vec3 vector)
{
	printf("vec3:\nx=%.20f\ny=%.20f\nz=%.20f\n", vector.x, vector.y, vector.z);
}
