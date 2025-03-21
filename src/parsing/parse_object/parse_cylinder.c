/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:46:50 by rgiambon          #+#    #+#             */
/*   Updated: 2025/03/21 09:08:29 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libft.h"
#include "numbers.h"
#include "scene.h"
#include "parsing.h"
#include "error_managment.h"
#include "custom_errors.h"

void	parse_height_cylinder(t_error *error, char *token, t_cylinder *cy)
{
	if (!ft_isfloat(token) || ft_isfloatoverflow(token))
	{
		error_set(error, NOT_A_NUMBER);
		error_msg_append(error, "Invalid height value: not a valid number", 0);
		return ;
	}
	cy->height = ft_atof(token);
	if (cy->height <= 0)
	{
		error_set(error, INVALID_RANGE);
		error_msg_append(error, "Height must be positive", 0);
		return ;
	}
}

void	parse_diameter_cylinder(t_error *error, char *token, t_cylinder *cy)
{
	if (!ft_isfloat(token) || ft_isfloatoverflow(token))
	{
		error_set(error, NOT_A_NUMBER);
		return ;
	}
	cy->diameter = ft_atof(token);
	if (cy->diameter <= 0)
	{
		error_set(error, INVALID_RANGE);
		error_msg_append(error, "Diameter must be positive", 0);
		return ;
	}
}

void	parse_orientation_cylinder(t_error *error, char *token, t_cylinder *cy)
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
	cy->orientation = parse_vector(coordinates);
	if (orientation_error(&cy->orientation))
	{
		error_set(error, INVALID_RANGE);
		free_array(coordinates);
		return ;
	}
	free_array(coordinates);
}

void	parse_position_cylinder(t_error *error, char *token, t_cylinder *cy)
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
	cy->position = parse_vector(coordinates);
	free_array(coordinates);
}

t_object	parse_cylinder(t_error *error, char *line)
{
	t_object	object;
	t_cylinder	*cylinder;
	char		**tokens;

	cylinder = (t_cylinder *)&object;
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
	parse_position_cylinder(error, tokens[1], cylinder);
	parse_orientation_cylinder(error, tokens[2], cylinder);
	parse_diameter_cylinder(error, tokens[3], cylinder);
	parse_height_cylinder(error, tokens[4], cylinder);
	parse_color_cylinder(error, tokens[5], cylinder);
	free_array(tokens);
	if (error->errnum)
		error_msg_append(error, "cylinder: ", 0);
	return (object);
}
