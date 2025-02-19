/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:39:00 by rgiambon          #+#    #+#             */
/*   Updated: 2025/02/19 13:23:32 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minirt.h"
#include "../../inc/parsing.h"
#include "../../inc/scene.h"
#include "../../inc/error_managment.h"
#include "../../inc/custom_errors.h"

void	parse_light_color(t_error *error, char *token, t_light *light)
{
	char	**color;

	color = ft_split(token, ',');
	if (!color)
	{
		error_set(error, ENOMEM);
		error_msg_append(error, "Failed to allocate memory for light color", 0);
		error_manage(error);
	}
	if (color_error(color))
	{
		error_set(error, INVALID_COLOR_FORMAT);
		error_msg_append(error, "Invalid color format in light", 0);
		error_msg_append_line(error, __LINE__);
		free_array(color);
		error_manage(error);
	}
	light->light_color.r = ft_atoi(color[0]);
	light->light_color.g = ft_atoi(color[1]);
	light->light_color.b = ft_atoi(color[2]);
	free_array(color);
}

void	parse_light_ratio(t_error *error, char *token, t_light *light)
{
	if (!ft_isfloat(token) || ft_isfloatoverflow(token))
	{
		error_set(error, NOT_A_NUMBER);
		error_msg_append(error, "Invalid light ratio: not a valid number", 0);
		error_msg_append_line(error, __LINE__);
		error_manage(error);
	}
	light->light_ratio = ft_atof(token);
	if (light->light_ratio < 0.0 || light->light_ratio > 1.0)
	{
		error_set(error, INVALID_RATIO_RANGE);
		error_msg_append(error, "Light ratio must be between 0.0 and 1.0", 0);
		error_msg_append_line(error, __LINE__);
		error_manage(error);
	}
}

void	parse_light_position(t_error *error, char *token, t_light *light)
{
	char	**coordinates;

	coordinates = ft_split(token, ',');
	if (!coordinates)
	{
		error_set(error, ENOMEM);
		error_msg_append(error, "Failed to allocate memory for light position", 0);
		error_manage(error);
	}
	if (format_error(coordinates))
	{
		error_set(error, INVALID_COORDINATE_FORMAT);
		error_msg_append(error, "Invalid coordinate format in light position", 0);
		error_msg_append_line(error, __LINE__);
		free_array(coordinates);
		error_manage(error);
	}
	light->position.x = ft_atof(coordinates[0]);
	light->position.y = ft_atof(coordinates[1]);
	light->position.z = ft_atof(coordinates[2]);
	free_array(coordinates);
}

t_object	parse_light(t_error *error, char *line)
{
	t_light	light;
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens)
	{
		error_set(error, );
		error_msg_append(error, "Wrong number of ar for light", 0);	
		error_manage(error);
	}
	if (ft_arraylen(tokens) != 4)
	{
		error_set(error, WRONG_TOKENS_COUNT);
		error_msg_append(error, "Wrong number of tokens for light", 0);
		error_manage(error);
	}
	parse_light_position(error, tokens[1], &light);
	parse_light_ratio(error, tokens[2], &light);
	parse_light_color(error, tokens[3], &light);
	return (*((t_object *)&light);
}
