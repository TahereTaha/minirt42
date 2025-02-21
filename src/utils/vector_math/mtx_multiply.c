/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_multiply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:10:57 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/21 14:13:51 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_math.h"

t_vec2	vec2_mtx2_multiplication(t_vec2 vector, t_mtx2 matrix)
{
	t_vec2	result;
	t_mtx2	scaled_basis;

	scaled_basis.i_hat = vec2_scale(matrix.i_hat, vector.x);
	scaled_basis.j_hat = vec2_scale(matrix.j_hat, vector.y);
	result = vec2_addition(scaled_basis.i_hat, scaled_basis.j_hat);
	return (result);
}

t_vec3	vec3_mtx3_multiplication(t_vec3 vector, t_mtx3 matrix)
{
	t_vec3	result;
	t_mtx3	scaled_basis;

	scaled_basis.i_hat = vec3_scale(matrix.i_hat, vector.x);
	scaled_basis.j_hat = vec3_scale(matrix.j_hat, vector.y);
	scaled_basis.k_hat = vec3_scale(matrix.k_hat, vector.z);
	result = vec3_addition(scaled_basis.i_hat, scaled_basis.j_hat);
	result = vec3_addition(result, scaled_basis.k_hat);
	return (result);
}

t_mtx2	mtx2_mtx2_multiplication(t_mtx2 matrix1, t_mtx2 matrix2)
{
	t_mtx2	result;

	result.i_hat = vec2_mtx2_multiplication(matrix2.i_hat, matrix1);
	result.j_hat = vec2_mtx2_multiplication(matrix2.j_hat, matrix1);
	return (result);
}

t_mtx3	mtx3_mtx3_multiplication(t_mtx3 matrix1, t_mtx3 matrix2)
{
	t_mtx3	result;

	result.i_hat = vec3_mtx3_multiplication(matrix2.i_hat, matrix1);
	result.j_hat = vec3_mtx3_multiplication(matrix2.j_hat, matrix1);
	result.k_hat = vec3_mtx3_multiplication(matrix2.k_hat, matrix1);
	return (result);
}
