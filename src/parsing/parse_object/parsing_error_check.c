/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:04:45 by rgiambon          #+#    #+#             */
/*   Updated: 2025/04/08 11:02:53 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "numbers.h"
#include "scene.h"
#include "parsing.h"
#include "error_managment.h"
#include "custom_errors.h"
#include "minirt.h"

int	orientation_error(t_vec3 *orientation)
{
	if (orientation->x > 1 || orientation->x < -1)
		return (1);
	if (orientation->y > 1 || orientation->y < -1)
		return (1);
	if (orientation->z > 1 || orientation->z < -1)
		return (1);
	return (0);
}

int	color_error(t_color *color)
{
	if (color->r < 0 || color->r > 255)
		return (1);
	if (color->g < 0 || color->g > 255)
		return (1);
	if (color->b < 0 || color->b > 255)
		return (1);
	return (0);
}

void	free_array(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

int	ft_arraylen(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}
