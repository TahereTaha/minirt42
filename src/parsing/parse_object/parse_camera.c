/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:12:23 by rgiambon          #+#    #+#             */
/*   Updated: 2025/02/19 13:25:38 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/scene.h"
#include "../../inc/parsing.h"
#include "../../inc/error_managment.h"
#include "../../inc/custom_errors.h"

//add this two functions to utils of some kind
void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	ft_arraylen(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	parse_fov_rad(t_error *error, char *token, t_camera *cam)
{
	if (!ft_isfloat(token) || ft_isfloatoverflow(token))
	{
		error_set(error, NOT_A_NUMBER);
		error_msg_append(error, "Invalid FOV value: not a valid number", 0);
		error_msg_append_line(error, __LINE__);
		error_manage(error);
	}
	cam->fov_rad = ft_atof(token);
	if (cam->fov_rad < 0 || cam->fov_rad > 180)
	{
		error_set(error, INVALID_FOV_RANGE);
		error_msg_append(error, "FOV must be between 0 and 180 degrees", 0);
		error_msg_append_line(error, __LINE__);
		error_manage(error);
	}
}

void	parse_orientation(t_error *error, char *token, t_camera *cam)
{
	char	**coordinates;

	coordinates = ft_split(token, ',');
	if (!coordinates)
	{
		error_set(error, ENOMEM);
		error_msg_append(error, "Failed to allocate memory for camera orientation", 0);
		error_manage(error);
	}
	if (format_error(coordinates))
	{
		error_set(error, INVALID_COORDINATE_FORMAT);
		error_msg_append(error, "Invalid coordinate format in camera orientation", 0);
		error_msg_append_line(error, __LINE__);
		free_array(coordinates);
		error_manage(error);
	}
	cam->orientation.x = ft_atof(coordinates[0]);
	cam->orientation.y = ft_atof(coordinates[1]);
	cam->orientation.z = ft_atof(coordinates[2]);
	if (orientation_error(&cam->orientation))
	{
		error_set(error, INVALID_ORIENTATION);
		error_msg_append(error, "Camera orientation vector must be normalized (-1 to 1)", 0);
		error_msg_append_line(error, __LINE__);
		free_array(coordinates);
		error_manage(error);
	}
	free_array(coordinates);
}

void	parse_view_point(t_error *error, char *token, t_camera *cam)
{
	char	**coordinates;

	coordinates = ft_split(token, ',');
	if (!coordinates)
	{
		error_set(error, ENOMEM);
		error_msg_append(error, "Failed to allocate memory for camera position", 0);
		error_manage(error);
	}
	if (format_error(coordinates))
	{
		error_set(error, INVALID_COORDINATE_FORMAT);
		error_msg_append(error, "Invalid coordinate format in camera position", 0);
		error_msg_append_line(error, __LINE__);
		free_array(coordinates);
		error_manage(error);
	}
	cam->view_point.x = ft_atof(coordinates[0]);
	cam->view_point.y = ft_atof(coordinates[1]);
	cam->view_point.z = ft_atof(coordinates[2]);
	free_array(coordinates);
}

t_object	parse_camera(t_error *error, char *line)
{
	t_camera	cam;
	char		**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens)
		/*error*/
	if (ft_arraylen(tokens) != 4)
	{
		error_set(error, WRONG_TOKENS_COUNT);
		error_msg_append(error, "Wrong number of tokens for camera", 0);
		error_manage(error);
	}
	parse_view_point(error, tokens[1], &cam);
	parse_orientation(error, tokens[2], &cam);
	parse_fov_rad(error, tokens[3], &cam);
	return (*((t_object *)&cam));
}
