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

void	parse_color_plane(char *input, t_light *plane)
{
	char	**color;

	color = ft_split(token, ",")
	if (!color)
		/*malloc error*/
	if (colors_error(color))
		/*format error*/
	plane->color->r = ft_atoi(color[0]); 
	plane->color->g = ft_atoi(color[1]);
	plane->color->b = ft_atoi(color[2]);

	free_array(colors);
}


void	parse_orientation_plane(char *input, t_plane *plane)
{
	char	**coordinates;

	coordinates = ft_split(input, ",");
	if (!coordinates)
		/*exit malloc error*/
	if (check_error_format(coordinates))
		/*exit formatt error*/
	plane->orientation->x = ft_atof(coordinates[0]);
	plane->orientation->y = ft_atof(coordinates[1]);
	plane->orientation->z = ft_atof(coordinates[2]);
	if (orientation_error(plane->orientation))
		/*exit direction error*/
	free_array(coordinates);	

}


void	parse_position_plane(char *input, t_plane *plane)
{
	char	**coordinates;
	
	coordinates = ft_split(input, ",");
	if (!coordinates)
		/*exit with error malloc*/
	if (check_error_format(coordinates))
		/*exit with erro format*/
	plane->position->x = ft_atof(coordinates[0]);
	plane->position->y = ft_atof(coordinates[1]);
	plane->position->z = ft_atof(coordinates[2]);

	free_array(coordinates);
}


t_plane	*parse_plane(char **tokens, t_scene *scene)
{
	t_plane	plane;

	if (ft_arraylen(tokens) != 4)
		/*error too few args*/
	parse_position_plane(tokens[1], &plane);
	parse_orientation_plane(tokens[2], &plane);
	parse_color_plane(tokens[3], &plane);
	
	return (plane);
}
