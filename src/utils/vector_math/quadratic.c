/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:55:57 by rgiambon          #+#    #+#             */
/*   Updated: 2025/03/21 11:00:28 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "math.h"

int	solve_quadratic(double *coefficients, double *roots)
{
	double	discriminant;

	discriminant = coefficients[1] * coefficients[1]
		- 4.0 * coefficients[0] * coefficients[2];
	if (discriminant < 0)
		return (0);
	roots[0] = (-coefficients[1] - sqrt(discriminant)) \
	/ (2.0 * coefficients[0]);
	roots[1] = (-coefficients[1] + sqrt(discriminant)) \
	/ (2.0 * coefficients[0]);
	return (1);
}
