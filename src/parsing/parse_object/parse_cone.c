/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:13:08 by rgiambon          #+#    #+#             */
/*   Updated: 2025/04/08 10:20:23 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libft.h"
#include "numbers.h"
#include "scene.h"
#include "parsing.h"
#include "error_managment.h"
#include "custom_errors.h"

void	parse_height_cone(t_error *error, char *token, t_cone *co)
{
	if (!ft_isfloat(token) || ft_isfloatoverflow(token))
	{
		error_set(error, NOT_A_NUMBER);
		error_msg_append(error, "Invalid height value: not a valid number", 0);
		return ;
	}
	co->height = ft_atof(token);
	if (co->height <= 0)
	{
		error_set(error, INVALID_RANGE);
		error_msg_append(error, "Height must be positive", 0);
		return ;
	}
}

void	parse_diameter_cone(t_error *error, char *token, t_cone *co)
{
	if (!ft_isfloat(token) || ft_isfloatoverflow(token))
	{
		error_set(error, NOT_A_NUMBER);
		return ;
	}
	co->diameter = ft_atof(token);
	if (co->diameter <= 0)
	{
		error_set(error, INVALID_RANGE);
		error_msg_append(error, "Diameter must be positive", 0);
		return ;
	}
}

void	parse_orientation_cone(t_error *error, char *token, t_cone *co)
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
	co->orientation = parse_vector(coordinates);
	if (orientation_error(&co->orientation))
	{
		error_set(error, INVALID_RANGE);
		free_array(coordinates);
		return ;
	}
	free_array(coordinates);
}

void	parse_position_cone(t_error *error, char *token, t_cone *co)
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
	co->position = parse_vector(coordinates);
	free_array(coordinates);
}

t_object	parse_cone(t_error *error, char *line)
{
	t_object	object;
	char		**tokens;

	object.kind = CONE;
	tokens = ft_split(line, ' ');
	if (!tokens)
	{
		error_set(error, errno);
		return (object);
	}
	if (ft_arraylen(tokens) != 6)
	{
		error_set(error, INVALID_FORMAT);
		free_array(tokens);
		return (object);
	}
	parse_position_cone(error, tokens[1], (t_cone *)&object);
	parse_orientation_cone(error, tokens[2], (t_cone *)&object);
	parse_diameter_cone(error, tokens[3], (t_cone *)&object);
	parse_height_cone(error, tokens[4], (t_cone *)&object);
	parse_color_cone(error, tokens[5], (t_cone *)&object);
	free_array(tokens);
	return (object);
}
