/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:44:53 by rgiambon          #+#    #+#             */
/*   Updated: 2025/03/03 12:11:30 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libft.h"
#include "numbers.h"
#include "scene.h"
#include "parsing.h"
#include "error_managment.h"
#include "custom_errors.h"

void	parse_color_plane(t_error *error, char *token, t_plane *plane)
{
	char	**color;

	color = ft_split(token, ',');
	if (!color)
	{
		error_set(error, errno);
		error_msg_append(error, "Failed to allocate memory for plane color", 0);
		return ;
	}
	if (format_error(color))
	{
		error_set(error, INVALID_FORMAT);
		error_msg_append(error, "Invalid color format in plane", 0);
		free_array(color);
		return ;
	}
	plane->color.r = ft_atoi(color[0]);
	plane->color.g = ft_atoi(color[1]);
	plane->color.b = ft_atoi(color[2]);
	if (color_error(&plane->color))
	{
		error_set(error, INVALID_RANGE);
		error_msg_append(error, "Color values must be between 0 and 255", 0);
		free_array(color);
		return ;
	}
	free_array(color);
}

void	parse_orientation_plane(t_error *error, char *token, t_plane *plane)
{
	char	**coordinates;

	coordinates = ft_split(token, ',');
	if (!coordinates)
	{
		error_set(error, errno);
		error_msg_append(error, "Failed to allocate memory for plane orientation", 0);
		return ;
	}
	if (format_error(coordinates))
	{
		error_set(error, INVALID_FORMAT);
		error_msg_append(error, "Invalid coordinate format in plane orientation", 0);
		free_array(coordinates);
		return ;
	}
	plane->orientation.x = ft_atof(coordinates[0]);
	plane->orientation.y = ft_atof(coordinates[1]);
	plane->orientation.z = ft_atof(coordinates[2]);
	if (orientation_error(&plane->orientation))
	{
		error_set(error, INVALID_RANGE);
		error_msg_append(error, "Plane orientation vector must be normalized (-1 to 1)", 0);
		free_array(coordinates);
		return ;
	}
	free_array(coordinates);
}

void	parse_position_plane(t_error *error, char *token, t_plane *plane)
{
	char	**coordinates;

	coordinates = ft_split(token, ',');
	if (!coordinates)
	{
		error_set(error, errno);
		error_msg_append(error, "Failed to allocate memory for plane position", 0);
		return ;
	}
	if (format_error(coordinates))
	{
		error_set(error, INVALID_FORMAT);
		error_msg_append(error, "Invalid coordinate format in plane position", 0);
		free_array(coordinates);
		return ;
	}
	plane->position.x = ft_atof(coordinates[0]);
	plane->position.y = ft_atof(coordinates[1]);
	plane->position.z = ft_atof(coordinates[2]);
	free_array(coordinates);
}

t_object	parse_plane(t_error *error, char *line)
{
	t_object	object;
	t_plane		*plane;
	char		**tokens;

	plane = (t_plane *)&object;
	tokens = ft_split(line, ' ');
	if (!tokens)
	{
		error_set(error, errno);
		error_msg_append(error, "Failed to allocate memory for plane tokens", 0);
		return (object);
	}
	if (ft_arraylen(tokens) != 4)
	{
		error_set(error, WRONG_TOKENS_COUNT);
		error_msg_append(error, "Wrong number of tokens for plane", 0);
		return (object);
	}
	parse_position_plane(error, tokens[1], plane);
	parse_orientation_plane(error, tokens[2], plane);
	parse_color_plane(error, tokens[3], plane);
	free_array(tokens);
	return (object);
}
