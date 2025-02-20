/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:46:50 by rgiambon          #+#    #+#             */
/*   Updated: 2025/02/13 14:19:30 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/scene.h"
#include "../../inc/parsing.h"
#include "../../inc/error_managment.h"
#include "../../inc/custom_errors.h"
#include "../../inc/utils.h"

void	parse_color_cylinder(t_error *error, char *token, t_cylinder *cylinder)
{
	char	**color;

	color = ft_split(token, ',');
	if (!color)
	{
		error_set(error, errno);
		error_msg_append(error, "Failed to allocate memory for cylinder color", 0);
		error_manage(error);
	}
	if (format_error(color))
	{
		error_set(error, INVALID_FORMAT);
		error_msg_append(error, "Invalid color format in cylinder", 0);
		free_array(color);
		error_manage(error);
	}
	cylinder->color.r = ft_atoi(color[0]);
	cylinder->color.g = ft_atoi(color[1]);
	cylinder->color.b = ft_atoi(color[2]);
	if (color_error(&cylinder->color))
	{
		error_set(error, INVALID_RANGE);
		error_msg_append(error, "Color values must be between 0 and 255", 0);
		free_array(color);
		error_manage(error);
	}
	free_array(color);
}

void	parse_height_cylinder(t_error *error, char *token, t_cylinder *cylinder)
{
	if (!ft_isfloat(token) || ft_isfloatoverflow(token))
	{
		error_set(error, NOT_A_NUMBER);
		error_msg_append(error, "Invalid height value: not a valid number", 0);
		error_manage(error);
	}
	cylinder->height = ft_atof(token);
	if (cylinder->height <= 0)
	{
		error_set(error, INVALID_RANGE);
		error_msg_append(error, "Height must be positive", 0);
		error_manage(error);
	}
}

void	parse_diameter_cylinder(t_error *error, char *token, t_cylinder *cylinder)
{
	if (!ft_isfloat(token) || ft_isfloatoverflow(token))
	{
		error_set(error, NOT_A_NUMBER);
		error_msg_append(error, "Invalid diameter value: not a valid number", 0);
		error_manage(error);
	}
	cylinder->diameter = ft_atof(token);
	if (cylinder->diameter <= 0)
	{
		error_set(error, INVALID_RANGE);
		error_msg_append(error, "Diameter must be positive", 0);
		error_manage(error);
	}
}

void	parse_orientation_cylinder(t_error *error, char *token, t_cylinder *cylinder)
{
	char	**coordinates;

	coordinates = ft_split(token, ',');
	if (!coordinates)
	{
		error_set(error, errno);
		error_msg_append(error, "Failed to allocate memory for cylinder orientation", 0);
		error_manage(error);
	}
	if (format_error(coordinates))
	{
		error_set(error, INVALID_FORMAT);
		error_msg_append(error, "Invalid coordinate format in cylinder orientation", 0);
		free_array(coordinates);
		error_manage(error);
	}
	cylinder->orientation.x = ft_atof(coordinates[0]);
	cylinder->orientation.y = ft_atof(coordinates[1]);
	cylinder->orientation.z = ft_atof(coordinates[2]);
	if (orientation_error(&cylinder->orientation))
	{
		error_set(error, INVALID_RANGE);
		error_msg_append(error, "Cylinder orientation vector must be normalized (-1 to 1)", 0);
		free_array(coordinates);
		error_manage(error);
	}
	free_array(coordinates);
}

void	parse_position_cylinder(t_error *error, char *token, t_cylinder *cylinder)
{
	char	**coordinates;

	coordinates = ft_split(token, ',');
	if (!coordinates)
	{
		error_set(error, errno);
		error_msg_append(error, "Failed to allocate memory for cylinder position", 0);
		error_manage(error);
	}
	if (format_error(coordinates))
	{
		error_set(error, INVALID_FORMAT);
		error_msg_append(error, "Invalid coordinate format in cylinder position", 0);
		free_array(coordinates);
		error_manage(error);
	}
	cylinder->position.x = ft_atof(coordinates[0]);
	cylinder->position.y = ft_atof(coordinates[1]);
	cylinder->position.z = ft_atof(coordinates[2]);
	free_array(coordinates);
}

t_object	parse_cylinder(t_error *error, char *line)
{
	t_cylinder	cylinder;
	char		**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens)
	{
		error_set(error, errno);
		error_msg_append(error, "Failed to allocate memory for cylinder tokens", 0);
		error_manage(error);
	}
	if (ft_arraylen(tokens) != 6)
	{
		error_set(error, WRONG_TOKENS_COUNT);
		error_msg_append(error, "Wrong number of tokens for cylinder", 0);
		error_manage(error);
	}
	parse_position_cylinder(error, tokens[1], &cylinder);
	parse_orientation_cylinder(error, tokens[2], &cylinder);
	parse_diameter_cylinder(error, tokens[3], &cylinder);
	parse_height_cylinder(error, tokens[4], &cylinder);
	parse_color_cylinder(error, tokens[5], &cylinder);
	return (*((t_object *)&cylinder));
}
