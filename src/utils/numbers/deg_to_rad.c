/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deg_to_rad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:44:42 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/24 22:32:18 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numbers.h"

double	deg_to_rad(double deg)
{
	double	rad;

	rad = deg * PI / 180;
	return (rad);
}
