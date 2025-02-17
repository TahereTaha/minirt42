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

void	parse_height_cylinder(char *token, t_cylinder *cylinder)
{
	/*error check... what to check for???*/

	if (ft_isfloat(token))
	{
		if (!is_floatoverflow(token))
			cylinder->height = ft_atof(input);
		else
		{
			printf("ERROR: overflow\n");
			exit ();
		}
	}
	else if (ft_isint(token))
	{
		if (!is_intoverflow(token))
			cylinder->height = ft_atoi(token);
		else
		{
			printf("ERROR: overflow\n");
			exit ();
		}
	}
	else
	{
		printf("ERROR: format\n");
		exit ();
	}
}

void	parse_diameter_cylinder(char *token, t_cylinder *cylinder)
{
	/*error check... what to check for???*/

	if (ft_isfloat(token))
	{
		if (!is_floatoverflow(token))
			cylinder->diameter = ft_atof(token);
		else
		{
			printf("ERROR: overflow\n");
			exit ();
		}
	}
	else if (ft_isint(token))
	{
		if (!is_intoverflow(token))
			cylinder->diameter = ft_atoi(token);
		else
		{
			printf("ERROR: overflow\n");
			exit ();
		}
	}
	else
	{
		printf("ERROR: format\n");
		exit ();
	}
}

void	parse_color_cylinder(char *token, t_cylinder *cylinder)
{
	char	**color;

	color = ft_split(token, ',')
	if (!color)
	{
		printf("ERROR: malloc\n");
		exit ();
	}
	if (colors_error(color))
	{
		printf("ERROR: color\n");
		exit ();
	}
	cylinder->color.r = ft_atoi(color[0]); 
	cylinder->color.g = ft_atoi(color[1]);
	cylinder->color.b = ft_atoi(color[2]);

	free_array(color);
}

void	parse_orientation_cylinder(char *token, t_cylinder *cylinder)
{
	char	**coordinates;

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
	cylinder->orientation.x = ft_atof(coordinates[0]);
	cylinder->orientation.y = ft_atof(coordinates[1]);
	cylinder->orientation.z = ft_atof(coordinates[2]);
	if (orientation_error(cylinder->orientation))
	{
		printf("ERROR: range\n");
		exit ();
	}
	free_array(coordinates);	
}

void	parse_position_cylinder(char *token, t_cylinder *cylinder)
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
	cylinder->position.x = ft_atof(tokens[0]);
	cylinder->position.y = ft_atof(tokens[1]);
	cylinder->position.z = ft_atof(tokens[2]);

	free_array(coordinates);
}

t_cylinder	*parse_cylinder(char **tokens, t_scene *scene)
{
	t_cylinder	*cylinder;

	if (arraylen(tokens) != 6)
	{
		printf("ERROR: wrong args\n");
		exit ();
	}
	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
	{
		printf("ERROR: malloc\n");
		exit ();
	}
	parse_position_cylinder(tokens[1], cylinder);
	parse_orientation_cylinder(tokens[2], cylinder);
	parse_diameter_cylinder(tokens[3], cylinder);
	parse_height_cylinder(tokens[4], cylinder);
	parse_color_cylinder(tokens[5], cylinder);

	(void)scene;

	return (cylinder);
}
