/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:12:23 by rgiambon          #+#    #+#             */
/*   Updated: 2025/04/08 10:16:37 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libft.h"
#include "numbers.h"
#include "scene.h"
#include "parsing.h"
#include "error_managment.h"
#include "custom_errors.h"

void	parse_fov_rad(t_error *error, char *token, t_camera *cam)
{
	if (!ft_isfloat(token) || ft_isfloatoverflow(token))
	{
		error_set(error, NOT_A_NUMBER);
		error_msg_append(error, "Invalid FOV value: not a valid number", 0);
		return ;
	}
	cam->fov_rad = ft_atof(token);
	if (cam->fov_rad < 0 || cam->fov_rad > 180)
	{
		error_set(error, INVALID_RANGE);
		error_msg_append(error, "FOV must be between 0 and 180 degrees", 0);
		return ;
	}
}

t_vec3	parse_vector(char **coordinates)
{
	t_vec3	vec;

	vec.x = ft_atof(coordinates[0]);
	vec.y = ft_atof(coordinates[1]);
	vec.z = ft_atof(coordinates[2]);
	return (vec);
}

void	parse_orientation(t_error *error, char *token, t_camera *cam)
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
		error_msg_append(error, "Invalid orientation", 0);
		free_array(coordinates);
		return ;
	}
	cam->orientation = parse_vector(coordinates);
	if (orientation_error(&cam->orientation))
	{
		error_set(error, INVALID_RANGE);
		error_msg_append(error, "orientation not normalized", 0);
		free_array(coordinates);
		return ;
	}
	free_array(coordinates);
}

void	parse_view_point(t_error *error, char *token, t_camera *cam)
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
		error_msg_append(error, "Invalid coordinate format", 0);
		free_array(coordinates);
		return ;
	}
	cam->view_point = parse_vector(coordinates);
	free_array(coordinates);
}

t_object	parse_camera(t_error *error, char *line)
{
	t_object	object;
	t_camera	*cam;
	char		**tokens;

	cam = (t_camera *)&object;
	tokens = ft_split(line, ' ');
	if (!tokens)
	{
		error_set(error, errno);
		error_msg_append(error, "camera: ", 0);
		return (object);
	}
	if (ft_arraylen(tokens) != 4)
	{
		error_set(error, WRONG_TOKENS_COUNT);
		error_msg_append(error, "camera: wrong numbre of tokens", 0);
		return (object);
	}
	parse_view_point(error, tokens[1], cam);
	parse_orientation(error, tokens[2], cam);
	parse_fov_rad(error, tokens[3], cam);
	free_array(tokens);
	if (error->errnum)
		error_msg_append(error, "cammera: ", 0);
	return (object);
}
