/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_matrix_multiply.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:10:57 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/20 10:10:57 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vector_math.h"

t_matrix3	matrix3_multiply(t_matrix3 a, t_matrix3 b)
{
	t_matrix3	result;
	int			i;
	int			j;
	int			k;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			result.m[i][j] = 0;
			k = 0;
			while (k < 3)
			{
				result.m[i][j] += a.m[i][k] * b.m[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (result);
}
