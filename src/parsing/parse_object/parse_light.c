/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:39:00 by rgiambon          #+#    #+#             */
/*   Updated: 2025/03/21 08:56:26 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libft.h"
#include "numbers.h"
#include "scene.h"
#include "parsing.h"
#include "error_managment.h"
#include "custom_errors.h"

void	parse_light_light_color(t_error *error, char *token, t_light *light)
{
	char	**light_color;

	light_color = ft_split(token, ',');
	if (!light_color)
	{
		error_set(error, errno);
		return ;
	}
	if (format_error(light_color))
	{
		error_set(error, INVALID_FORMAT);
		free_array(light_color);
		return ;
	}
	light->light_color.r = ft_atoi(light_color[0]);
	light->light_color.g = ft_atoi(light_color[1]);
	light->light_color.b = ft_atoi(light_color[2]);
	if (color_error(&light->light_color))
	{
		error_set(error, INVALID_RANGE);
		free_array(light_color);
		return ;
	}
	free_array(light_color);
}

void	parse_light_ratio(t_error *error, char *token, t_light *light)
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
		return ;
	}
}

void	parse_light_position(t_error *error, char *token, t_light *light)
{
	char	**coordinates;

	coordinates = ft_split(token, ',');
	if (!coordinates)
	{
		error_set(error, errno);
		return ;
	}
	if (format_error(coordinates))
	{
		error_set(error, INVALID_FORMAT);
		free_array(coordinates);
		return ;
	}
	light->position.x = ft_atof(coordinates[0]);
	light->position.y = ft_atof(coordinates[1]);
	light->position.z = ft_atof(coordinates[2]);
	free_array(coordinates);
}

t_object	parse_light(t_error *error, char *line)
{
	t_object	object;
	t_light		*light;
	char		**tokens;

	light = (t_light *)&object;
	tokens = ft_split(line, ' ');
	if (!tokens)
	{
		error_set(error, errno);
		return (object);
	}
	if (ft_arraylen(tokens) != 4)
	{
		error_set(error, WRONG_TOKENS_COUNT);
		return (object);
	}
	parse_light_position(error, tokens[1], light);
	parse_light_ratio(error, tokens[2], light);
	parse_light_light_color(error, tokens[3], light);
	free_array(tokens);
	if (error->errnum)
		error_msg_append(error, "light: ", 0);
	return (object);
}
