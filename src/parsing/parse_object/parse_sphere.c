/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:12:12 by rgiambon          #+#    #+#             */
/*   Updated: 2025/04/08 10:18:05 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libft.h"
#include "numbers.h"
#include "scene.h"
#include "parsing.h"
#include "error_managment.h"
#include "custom_errors.h"

static t_color	parse_color(char **color)
{
	t_color	new_color;

	new_color.r = ft_atoi(color[0]);
	new_color.g = ft_atoi(color[1]);
	new_color.b = ft_atoi(color[2]);
	return (new_color);
}

void	parse_color_sphere(t_error *error, char *token, t_sphere *sphere)
{
	char	**color;

	color = ft_split(token, ',');
	if (!color)
	{
		error_set(error, errno);
		return ;
	}
	if (format_error(color, token))
	{
		error_set(error, INVALID_FORMAT);
		error_msg_append(error, "Invalid color format in sphere", 0);
		free_array(color);
		return ;
	}
	sphere->color = parse_color(color);
	if (color_error(&sphere->color))
	{
		error_set(error, INVALID_RANGE);
		error_msg_append(error, "Color values must be between 0 and 255", 0);
		free_array(color);
		return ;
	}
	free_array(color);
}

void	parse_diameter_sphere(t_error *error, char *token, t_sphere *sphere)
{
	if (!ft_isfloat(token) || ft_isfloatoverflow(token))
	{
		error_set(error, NOT_A_NUMBER);
		return ;
	}
	sphere->diameter = ft_atof(token);
	if (sphere->diameter <= 0)
	{
		error_set(error, INVALID_RANGE);
		return ;
	}
}

void	parse_position_sphere(t_error *error, char *token, t_sphere *sphere)
{
	char	**coordinates;

	coordinates = ft_split(token, ',');
	if (!coordinates)
	{
		error_set(error, errno);
		return ;
	}
	if (format_error(coordinates, token))
	{
		error_set(error, INVALID_FORMAT);
		free_array(coordinates);
		return ;
	}
	sphere->position.x = ft_atof(coordinates[0]);
	sphere->position.y = ft_atof(coordinates[1]);
	sphere->position.z = ft_atof(coordinates[2]);
	free_array(coordinates);
}

t_object	parse_sphere(t_error *error, char *line)
{
	t_object	object;
	t_sphere	*sphere;
	char		**tokens;

	sphere = (t_sphere *)&object;
	tokens = ft_split(line, ' ');
	if (!tokens)
	{
		error_set(error, errno);
		return (object);
	}
	if (ft_arraylen(tokens) != 4)
	{
		free_array(tokens);
		error_set(error, WRONG_TOKENS_COUNT);
		return (object);
	}
	parse_position_sphere(error, tokens[1], sphere);
	parse_diameter_sphere(error, tokens[2], sphere);
	parse_color_sphere(error, tokens[3], sphere);
	if (error->errnum)
		error_msg_append(error, "sphere: ", 0);
	free_array(tokens);
	return (object);
}
