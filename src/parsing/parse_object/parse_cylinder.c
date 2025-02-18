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

#include "../../inc/minirt.h"
#include "../../inc/parsing.h"
#include "../../inc/scene.h"
#include "../../inc/error_managment.h"
#include "../../inc/custom_errors.h"

void	parse_color_cylinder(t_error *error, char *token, t_cylinder *cylinder)
{
	char	**color;

	color = ft_split(token, ',');
	if (!color)
	{
		error_set(error, ENOMEM);
		error_msg_append(error, "Failed to allocate memory for cylinder color", 0);
		error_manage(error);
	}
	if (color_error(color))
	{
		error_set(error, INVALID_COLOR_FORMAT);
		error_msg_append(error, "Invalid color format in cylinder", 0);
		error_msg_append_line(error, __LINE__);
		free_array(color);
		error_manage(error);
	}
	cylinder->color.r = ft_atoi(color[0]);
	cylinder->color.g = ft_atoi(color[1]);
	cylinder->color.b = ft_atoi(color[2]);
	free_array(color);
}

void	parse_height_cylinder(t_error *error, char *token, t_cylinder *cylinder)
{
	if (!ft_isfloat(token) || ft_isfloatoverflow(token))
	{
		error_set(error, NOT_A_NUMBER);
		error_msg_append(error, "Invalid cylinder height: not a valid number", 0);
		error_msg_append_line(error, __LINE__);
		error_manage(error);
	}
	cylinder->height = ft_atof(token);
	if (cylinder->height <= 0)
	{
		error_set(error, INVALID_DIMENSION);
		error_msg_append(error, "Cylinder height must be positive", 0);
		error_msg_append_line(error, __LINE__);
		error_manage(error);
	}
}

void	parse_diameter_cylinder(t_error *error, char *token, t_cylinder *cylinder)
{
	if (!ft_isfloat(token) || ft_isfloatoverflow(token))
	{
		error_set(error, NOT_A_NUMBER);
		error_msg_append(error, "Invalid cylinder diameter: not a valid number", 0);
		error_msg_append_line(error, __LINE__);
		error_manage(error);
	}
	cylinder->diameter = ft_atof(token);
	if (cylinder->diameter <= 0)
	{
		error_set(error, INVALID_DIMENSION);
		error_msg_append(error, "Cylinder diameter must be positive", 0);
		error_msg_append_line(error, __LINE__);
		error_manage(error);
	}
}

void	parse_orientation_cylinder(t_error *error, char *token, t_cylinder *cylinder)
{
	char	**coordinates;

	coordinates = ft_split(token, ',');
	if (!coordinates)
	{
		error_set(error, ENOMEM);
		error_msg_append(error, "Failed to allocate memory for cylinder orientation", 0);
		error_manage(error);
	}
	if (format_error(coordinates))
	{
		error_set(error, INVALID_COORDINATE_FORMAT);
		error_msg_append(error, "Invalid coordinate format in cylinder orientation", 0);
		error_msg_append_line(error, __LINE__);
		free_array(coordinates);
		error_manage(error);
	}
	cylinder->orientation.x = ft_atof(coordinates[0]);
	cylinder->orientation.y = ft_atof(coordinates[1]);
	cylinder->orientation.z = ft_atof(coordinates[2]);
	if (orientation_error(&cylinder->orientation))
	{
		error_set(error, INVALID_ORIENTATION);
		error_msg_append(error, "Cylinder orientation vector must be normalized (-1 to 1)", 0);
		error_msg_append_line(error, __LINE__);
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
		error_set(error, ENOMEM);
		error_msg_append(error, "Failed to allocate memory for cylinder position", 0);
		error_manage(error);
	}
	if (format_error(coordinates))
	{
		error_set(error, INVALID_COORDINATE_FORMAT);
		error_msg_append(error, "Invalid coordinate format in cylinder position", 0);
		error_msg_append_line(error, __LINE__);
		free_array(coordinates);
		error_manage(error);
	}
	cylinder->position.x = ft_atof(coordinates[0]);
	cylinder->position.y = ft_atof(coordinates[1]);
	cylinder->position.z = ft_atof(coordinates[2]);
	free_array(coordinates);
}

t_cylinder	*parse_cylinder(t_error *error, char **tokens, t_scene *scene)
{
	t_cylinder	*cylinder;

	if (ft_arraylen(tokens) != 6)
	{
		error_set(error, WRONG_ARGUMENT_COUNT);
		error_msg_append(error, "Wrong number of arguments for cylinder", 0);
		error_msg_append_line(error, __LINE__);
		error_manage(error);
	}
	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
	{
		error_set(error, ENOMEM);
		error_msg_append(error, "Failed to allocate memory for cylinder", 0);
		error_manage(error);
	}
	parse_position_cylinder(error, tokens[1], cylinder);
	parse_orientation_cylinder(error, tokens[2], cylinder);
	parse_diameter_cylinder(error, tokens[3], cylinder);
	parse_height_cylinder(error, tokens[4], cylinder);
	parse_color_cylinder(error, tokens[5], cylinder);
	
	(void)scene;
	return (cylinder);
}
