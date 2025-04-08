/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:24:59 by rgiambon          #+#    #+#             */
/*   Updated: 2025/04/08 10:26:59 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "scene.h"
#include "parsing.h"
#include "error_managment.h"
#include "custom_errors.h"
#include "libft.h"
#include "numbers.h"

void	split_and_validate_color_format(t_error *error, \
char *token, char ***colors)
{
	*colors = ft_split(token, ',');
	if (!*colors)
	{
		error_set(error, errno);
		return ;
	}
	if (format_error(*colors))
	{
		error_set(error, INVALID_FORMAT);
		free_array(*colors);
		*colors = NULL;
	}
}

void	validate_color_components_are_integers(t_error *error, char **colors)
{
	int	i;

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
}

void	parse_and_validate_color_values(t_error *error, \
char **colors, t_cone *co)
{
	co->color.r = ft_atoi(colors[0]);
	co->color.g = ft_atoi(colors[1]);
	co->color.b = ft_atoi(colors[2]);
	if (color_error(&co->color))
	{
		error_set(error, INVALID_RANGE);
		free_array(colors);
		return ;
	}
}

void	parse_color_cone(t_error *error, char *token, t_cone *co)
{
	char	**colors;

	split_and_validate_color_format(error, token, &colors);
	if (!colors)
		return ;
	validate_color_components_are_integers(error, colors);
	if (!colors)
		return ;
	parse_and_validate_color_values(error, colors, co);
	free_array(colors);
}
