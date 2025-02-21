/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:12:12 by rgiambon          #+#    #+#             */
/*   Updated: 2025/02/21 11:11:24 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libft.h"
#include "numbers.h"
#include "scene.h"
#include "parsing.h"
#include "error_managment.h"
#include "custom_errors.h"

void	parse_color_sphere(t_error *error, char *token, t_sphere *sphere)
{
	char	**color;

	color = ft_split(token, ',');
	if (!color)
	{
		error_set(error, errno);
		error_msg_append(error, "Failed to allocate memory for sphere color", 0);
		return ;
	}
	if (format_error(color))
	{
		error_set(error, INVALID_FORMAT);
		error_msg_append(error, "Invalid color format in sphere", 0);
		free_array(color);
		return ;
	}
	sphere->color.r = ft_atoi(color[0]);
	sphere->color.g = ft_atoi(color[1]);
	sphere->color.b = ft_atoi(color[2]);
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
		error_msg_append(error, "Invalid diameter value: not a valid number", 0);
		error_manage(error);
	}
	sphere->diameter = ft_atof(token);
	if (sphere->diameter <= 0)
	{
		error_set(error, INVALID_RANGE);
		error_msg_append(error, "Diameter must be positive", 0);
		error_manage(error);
	}
}

void	parse_position_sphere(t_error *error, char *token, t_sphere *sphere)
{
	char	**coordinates;

	coordinates = ft_split(token, ',');
	if (!coordinates)
	{
		error_set(error, errno);
		error_msg_append(error, "Failed to allocate memory for sphere position", 0);
		error_manage(error);
	}
	if (format_error(coordinates))
	{
		error_set(error, INVALID_FORMAT);
		error_msg_append(error, "Invalid coordinate format in sphere position", 0);
		free_array(coordinates);
		error_manage(error);
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
		error_msg_append(error, "Wrong number of tokens for sphere: ", 0);
		return (object);
	}
	parse_position_sphere(error, tokens[1], sphere);
	parse_diameter_sphere(error, tokens[2], sphere);
	parse_color_sphere(error, tokens[3], sphere);
	free_array(tokens);
	return (object);
}
