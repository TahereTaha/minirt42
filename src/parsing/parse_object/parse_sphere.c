/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:12:12 by rgiambon          #+#    #+#             */
/*   Updated: 2025/02/13 14:06:10 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minirt.h"
#include "../../inc/parsing.h"
#include "../../inc/scene.h"
#include "../../inc/error_managment.h"
#include "../../inc/custom_errors.h"

void	parse_color_sphere(t_error *error, char *token, t_sphere *sphere)
{
	char	**color;

	color = ft_split(token, ',');
	if (!color)
	{
		error_set(error, ENOMEM);
		error_msg_append(error, "Failed to allocate memory for sphere color", 0);
		error_manage(error);
	}
	if (color_error(color))
	{
		error_set(error, INVALID_COLOR_FORMAT);
		error_msg_append(error, "Invalid color format in sphere", 0);
		error_msg_append_line(error, __LINE__);
		free_array(color);
		error_manage(error);
	}
	sphere->color.r = ft_atoi(color[0]); 
	sphere->color.g = ft_atoi(color[1]);
	sphere->color.b = ft_atoi(color[2]);
	free_array(color);
}

void	parse_diameter_sphere(t_error *error, char *token, t_sphere *sphere)
{
	/*error check... ?????*/

	if (ft_isfloat(token))
	{
		if (!is_floatoverflow(token))
			sphere->diameter = ft_atof(token);
		else
		{
			error_set(error, FLOAT_OVERFLOW);
			error_msg_append(error, "Sphere diameter value overflow", 0);
			error_msg_append_line(error, __LINE__);
			error_manage(error);
		}
	}
	else
	{
		if (!is_intoverflow(token))
			sphere->diameter = ft_atoi(token);
		else
		{
			error_set(error, INT_OVERFLOW);
			error_msg_append(error, "Sphere diameter value overflow", 0);
			error_msg_append_line(error, __LINE__);
			error_manage(error);
		}
	}
	if (sphere->diameter <= 0)
	{
		error_set(error, INVALID_DIMENSION);
		error_msg_append(error, "Sphere diameter must be positive", 0);
		error_msg_append_line(error, __LINE__);
		error_manage(error);
	}
}	

void	parse_position_sphere(t_error *error, char *token, t_sphere *sphere)
{
	char **coordinates;

	coordinates = ft_split(token, ',');
	if (!coordinates)
	{
		error_set(error, ENOMEM);
		error_msg_append(error, "Failed to allocate memory for sphere position", 0);
		error_manage(error);
	}
	if (format_error(coordinates))
	{
		error_set(error, INVALID_COORDINATE_FORMAT);
		error_msg_append(error, "Invalid coordinate format in sphere position", 0);
		error_msg_append_line(error, __LINE__);
		free_array(coordinates);
		error_manage(error);
	}
	sphere->position.x = ft_atof(coordinates[0]);
	sphere->position.y = ft_atof(coordinates[1]);
	sphere->position.z = ft_atof(coordinates[2]);

	free_array(coordinates);
}

t_sphere	*parse_sphere(t_error *error, char **tokens, t_scene *scene)
{
	t_sphere	*sphere;


	if (ft_arraylen(tokens) != 4)
	{
		error_set(error, WRONG_ARGUMENT_COUNT);
		error_msg_append(error, "Wrong number of arguments for sphere", 0);
		error_msg_append_line(error, __LINE__);
		error_manage(error);
	}
	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
	{
		error_set(error, ENOMEM);
		error_msg_append(error, "Failed to allocate memory for sphere", 0);
		error_manage(error);
	}
	parse_position_sphere(error, tokens[1], sphere);
	parse_diameter_sphere(error, tokens[2], sphere);
	parse_color_sphere(error, tokens[3], sphere);
	
	(void)scene;
	return (sphere);
}
