/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:24:59 by rgiambon          #+#    #+#             */
/*   Updated: 2025/04/08 10:20:38 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "scene.h"
#include "parsing.h"
#include "error_managment.h"
#include "custom_errors.h"
#include "libft.h"
#include "numbers.h"

void	parse_color_cone(t_error *error, char *token, t_cone *co)
{
	char	**colors;
	int		i;

	colors = ft_split(token, ',');
	if (!colors)
	{
		error_set(error, errno);
		return ;
	}
	if (format_error(colors, token))
	{
		error_set(error, INVALID_FORMAT);
		free_array(colors);
		return ;
	}
	i = 0;
	while (colors[i])
	{
		if (!ft_isint(colors[i]))
		{
			error_set(error, NOT_A_NUMBER);
			free_array(colors);
			return ;
		}
		i++;
	}
	co->color.r = ft_atoi(colors[0]);
	co->color.g = ft_atoi(colors[1]);
	co->color.b = ft_atoi(colors[2]);
	if (color_error(&co->color))
	{
		error_set(error, INVALID_RANGE);
		free_array(colors);
		return ;
	}
	free_array(colors);
}
