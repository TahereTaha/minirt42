/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:39:00 by rgiambon          #+#    #+#             */
/*   Updated: 2025/03/21 09:25:19 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <errno.h>
#include "libft.h"
#include "numbers.h"
#include "scene.h"
#include "parsing.h"
#include "error_managment.h"
#include "custom_errors.h"

void	parse_alight_color(t_error *error, char *token, t_ambient_light *light)
{
	char	**color;

	color = ft_split(token, ',');
	if (!color)
	{
		error_set(error, errno);
		return ;
	}
	if (format_error(color))
	{
		error_set(error, INVALID_FORMAT);
		free_array(color);
		return ;
	}
	light->light_color.r = ft_atoi(color[0]);
	light->light_color.g = ft_atoi(color[1]);
	light->light_color.b = ft_atoi(color[2]);
	if (color_error(&light->light_color))
	{
		error_set(error, INVALID_RANGE);
		free_array(color);
		return ;
	}
	free_array(color);
}

void	parse_alight_ratio(t_error *error, char *token, t_ambient_light *light)
{
	if (!ft_isfloat(token) || ft_isfloatoverflow(token))
	{
		error_set(error, NOT_A_NUMBER);
		error_msg_append(error, "Invalid light ratio: not a valid number", 0);
		return ;
	}
	light->light_ratio = ft_atof(token);
	if (light->light_ratio < 0.0 || light->light_ratio > 1.0)
	{
		error_set(error, INVALID_RANGE);
		error_msg_append(error, "Light ratio must be between 0.0 and 1.0", 0);
		return ;
	}
}

t_object	parse_ambient_light(t_error *error, char *line)
{
	t_object		object;
	t_ambient_light	*light;
	char			**tokens;

	light = (t_ambient_light *)&object;
	tokens = ft_split(line, ' ');
	if (!tokens)
	{
		error_set(error, errno);
		return (object);
	}
	if (ft_arraylen(tokens) != 3)
	{
		error_set(error, WRONG_TOKENS_COUNT);
		return (object);
	}
	parse_alight_ratio(error, tokens[1], light);
	parse_alight_color(error, tokens[2], light);
	free_array(tokens);
	if (error->errnum)
		error_msg_append(error, "ambient light: ", 0);
	return (object);
}
