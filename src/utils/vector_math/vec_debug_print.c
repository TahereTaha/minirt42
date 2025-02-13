/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_debug_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:21:55 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/12 11:01:42 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "vector_math.h"

void	vec2_print(t_vec2 vector)
{
	printf("vec2:x=%f,y=%f\n", vector.x, vector.y);
}

void	vec2_print_multiline(t_vec2 vector)
{
	printf("vec2:\nx=%f\ny=%f\n", vector.x, vector.y);
}

void	vec3_print(t_vec3 vector)
{
	printf("vec3:x=%f,y=%f,z=%f\n", vector.x, vector.y, vector.z);
}

void	vec3_print_multiline(t_vec3 vector)
{
	printf("vec3:\nx=%f\ny=%f\nz=%f\n", vector.x, vector.y, vector.z);
}
