/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_negate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 06:50:55 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/08 08:26:02 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_math.h"

t_mtx3	negate_matrix(t_mtx3 mtx)
{
	t_mtx3	
	mtx.i_hat = vec3_scale(mtx.i_hat, -1);
	mtx.j_hat = vec3_scale(mtx.i_hat, -1);
	mtx.k_hat = vec3_scale(mtx.i_hat, -1);
	return (mtx);
}
