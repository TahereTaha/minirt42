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

#include "../../inc/scene.h"
#include "../../inc/parsing.h"
#include "../../inc/error_managment.h"
#include "../../inc/custom_errors.h"
#include "../../inc/utils.h"
#include "../../inc/minirt.h"

bool	orientation_error(t_vec3 *orientation)
{
	double	length;

	if (orientation->x > 1 || orientation->x < -1)
		return (true);
	if (orientation->y > 1 || orientation->y < -1)
		return (true);
	if (orientation->z > 1 || orientation->z < -1)
		return (true);
	
	length = sqrt(orientation->x * orientation->x + 
				 orientation->y * orientation->y + 
				 orientation->z * orientation->z);
	if (fabs(length - 1.0) > 0.0001)
		return (true);
	return (false);
}

bool	format_error(char **coordinates)
{
	int	i;

	i = 0;
	if (!coordinates || ft_arraylen(coordinates) != 3)
		return (true);
	while (coordinates[i])
	{
		if (!ft_isfloat(coordinates[i]) || ft_isfloatoverflow(coordinates[i]))
			return (true);
		i++;
	}
	return (false);
}

bool	color_error(t_color *color)
{
	if (color->r < 0 || color->r > 255)
		return (true);
	if (color->g < 0 || color->g > 255)
		return (true);
	if (color->b < 0 || color->b > 255)
		return (true);
	return (false);
}
