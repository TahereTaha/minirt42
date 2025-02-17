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

void	parse_color_sphere(char *token, t_sphere *sphere)
{
	char	**color;

	color = ft_split(token, ',')
	if (!color)
	{
		printf("ERROR: malloc\n");
		exit ();
	}
	if (color_error(color))
	{
		printf("ERROR: format\n");
		exit ();
	}
	sphere->color.r = ft_atoi(color[0]); 
	sphere->color.g = ft_atoi(color[1]);
	sphere->color.b = ft_atoi(color[2]);

	free_array(color);
}

void	parse_diameter_sphere(char *token, t_sphere *sphere)
{
	/*error check... ?????*/

	if (ft_isfloat(token))
	{
		if (!is_floatoverflow(token))
			sphere->diameter = ft_atof(token);
		else
		{
			printf("ERROR: overflow\n");
			exit ();
		}
	}
	else
	{
		if (!is_intoverflow(token))
			sphere->diameter = ft_atoi(token);
		else
		{
			printf("ERROR: overflow\n");
			exit ();
		}
	}
}	

void	parse_position_sphere(char *token, t_sphere *sphere)
{
	char **coordinates;

	coordinates = ft_split(token, ',');
	if (!coordinates)
	{
		printf("ERROR: malloc\n");
		exit ();
	}
	if (format_error(coordinates))
	{
		printf("ERROR: format\n");
		exit ();
	}
	sphere->position.x = ft_atof(tokens[0]);
	sphere->position.y = ft_atof(tokens[1]);
	sphere->position.z = ft_atof(tokens[2]);

	free_array(coordinates);
}

t_sphere	*parse_sphere(char **tokens, t_scene *scene)
{
	t_sphere	*sphere;


	if (ft_arraylen(tokens) != 4)
	{
		printf("ERROR: wrong args\n");
		exit ();
	}
	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
	{
		printf("ERROR: malloc\n");
		exit ();
	}
	parse_position_sphere(tokens[1], sphere);
	parse_diameter_sphere(tokens[2]);
	parse_color_sphere(tokens[3]);

	return (sphere);
}
