/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:44:53 by rgiambon          #+#    #+#             */
/*   Updated: 2025/02/13 14:17:11 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	parse_color_plane(char *token, t_plane *plane)
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
	plane->color->r = ft_atoi(color[0]); 
	plane->color->g = ft_atoi(color[1]);
	plane->color->b = ft_atoi(color[2]);

	free_array(colors);
}


void	parse_orientation_plane(char *token, t_plane *plane)
{
	char	**coordinates;

	coordinates = ft_split(token,',');
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
	plane->orientation.x = ft_atof(coordinates[0]);
	plane->orientation.y = ft_atof(coordinates[1]);
	plane->orientation.z = ft_atof(coordinates[2]);
	if (orientation_error(plane->orientation))
	{
		printf("ERROR: range\n");
		exit ();
	}
	free_array(coordinates);	

}


void	parse_position_plane(char *token, t_plane *plane)
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
	plane->position.x = ft_atof(coordinates[0]);
	plane->position.y = ft_atof(coordinates[1]);
	plane->position.z = ft_atof(coordinates[2]);

	free_array(coordinates);
}


t_plane	*parse_plane(char **tokens, t_scene *scene)
{
	t_plane	*plane;

	if (ft_arraylen(tokens) != 4)
	{
		printf("ERROR: wrong args\n");
		exit ();
	}
	plane = malloc(sizeof(t_plane));
	if (!plane)
	{
		printf("ERROR: malloc\n");
		exit ();
	}
	parse_position_plane(tokens[1], &plane);
	parse_orientation_plane(tokens[2], &plane);
	parse_color_plane(tokens[3], &plane);
	
	return (plane);
}
