/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:44:53 by rgiambon          #+#    #+#             */
/*   Updated: 2025/04/08 10:19:10 by tatahere         ###   ########.fr       */
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
		return ;
	}
	if (format_error(color, token))
	{
		error_set(error, INVALID_FORMAT);
		free_array(color);
		return ;
	}
	plane->color.r = ft_atoi(color[0]);
	plane->color.g = ft_atoi(color[1]);
	plane->color.b = ft_atoi(color[2]);
	if (color_error(&plane->color))
	{
		error_set(error, INVALID_RANGE);
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
		return ;
	}
	if (format_error(coordinates, token))
	{
		error_set(error, INVALID_FORMAT);
		free_array(coordinates);
		return ;
	}
	plane->orientation = parse_vector(coordinates);
	if (orientation_error(&plane->orientation))
	{
		error_set(error, INVALID_RANGE);
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
		return ;
	}
	if (format_error(coordinates, token))
	{
		error_set(error, INVALID_FORMAT);
		free_array(coordinates);
		return ;
	}
	plane->position.x = ft_atof(coordinates[0]);
	plane->position.y = ft_atof(coordinates[1]);
	plane->position.z = ft_atof(coordinates[2]);
	free_array(coordinates);
}

void	plane_parse_bonus(t_error *error, t_plane *plane, char **tokens)
{
	plane->disrupt = get_disruption(error, tokens[4]);
	plane->bump_map = get_bump_map(error, tokens[5]);
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
		return (object);
	}
	if (ft_arraylen(tokens) != 6)
	{
		error_set(error, WRONG_TOKENS_COUNT);
		return (object);
	}
	parse_position_plane(error, tokens[1], plane);
	parse_orientation_plane(error, tokens[2], plane);
	parse_color_plane(error, tokens[3], plane);
	plane_parse_bonus(error, plane, tokens);
	free_array(tokens);
	if (error->errnum)
		error_msg_append(error, "plane: ", 0);
	return (object);
}
