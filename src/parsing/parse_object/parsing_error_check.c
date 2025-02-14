/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:04:45 by rgiambon          #+#    #+#             */
/*   Updated: 2025/02/13 14:11:30 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

bool	orientation_error(t_vec3 *orientation)
{
	if (direction->x > 1 || direction->x < -1)
		return (true);
	if (direction->y > 1 || direction->y < -1)
		return (true);
	if (direction->z > 1 || direction->z < -1)
		return (true);
	return (false);
}

bool	format_error(char **coordinates)
{
	int	i;

	i = 0;
	if (ft_arraylen(coordinates) != 3)
		return (1);
	while (coordinates[i])
	{
		if (!ft_isfloat(coordinates[i]) || /*float overflow*/)
			return (1);
		i++;
	}
	return (0);
}

bool	colors_error(char **color)
{
	int	i;

	i = 0;
	if (ft_arraylen(color) != 3)
		return (1);
	while (color[i])
	{
		/*check if int ?*/
		if (ft_atoi(color[i]) < 0 || ft_atoi(color[i]) > 255)
			return (1);
		i++;
	}
	return (0);
}

