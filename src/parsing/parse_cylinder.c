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

void	parse_height_cylinder(char *input, t_cylinder *cylinder)
{
	/*error check*/

	if (ft_isfloat(input))
	{
		if (!is_floatoverflow(input))
			cylinder->height = ft_atof(input);
		else
			/*overflow error*/
	}
	else if (ft_isint(input))
	{
		if (!is_intoverflow(input))
			cylinder->height = ft_atoi(input);
		else
			/*overflow error*/
	}
	else
		/*format error*/
}

void	parse_diameter_cylinder(char *input, t_cylinder *cylinder)
{
	/*error check*/

	if (ft_isfloat(input))
	{
		if (!is_floatoverflow(input))
			cylinder->diameter = ft_atof(input);
		else
			/*overflow error*/
	}
	else if (ft_isint(input))
	{
		if (!is_intoverflow(input))
			cylinder->diameter = ft_atoi(input);
		else
			/*overflow error*/
	}
	else
		/*format error*/
}

void	parse_color_cylinder(char *input, t_cylinder cylinder)
{
	char	**color;

	color = ft_split(token, ",")
	if (!color)
		/*malloc error*/
	if (colors_error(color))
		/*format error*/
	cylinder->color->r = ft_atoi(color[0]); 
	cylinder->color->g = ft_atoi(color[1]);
	cylinder->color->b = ft_atoi(color[2]);

	free_array(color);
}

void	parse_orientation_cylinder(char *input, t_cylinder cylinder)
{
	char	**coordinates;

	coordinates = ft_split(input, ",");
	if (!coordinates)
		/*exit malloc error*/
	if (check_error_format(coordinates))
		/*exit formatt error*/
	cylinder->orientation->x = ft_atof(coordinates[0]);
	cylinder->orientation->y = ft_atof(coordinates[1]);
	cylinder->orientation->z = ft_atof(coordinates[2]);
	if (orientation_error(cylinder->orientation))
		/*exit direction error*/
	free_array(coordinates);	


void	parse_position_cylinder(char *input, t_cylinder *cylinder)
{
	char **coordinates;

	coordinates = ft_split(token, ",");
	if (!coordinates)
		/*error malloc*/
	if (format_error(coordinates))
		/*error format*/
	cylinder->position->x = ft_atof(tokens[0]);
	cylinder->position->y = ft_atof(tokens[1]);
	cylinder->position->z = ft_atof(tokens[2]);

	free_array(coordinates);
}

t_cylinder	*parse_cylinder(char **tokens, t_scene *scene)
{
	t_cylinder	*cylinder;

	if (arraylen(tokens) != 6)
		/*error*/
	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		/*malloc error*/
	parse_position_cylinder(tokens[1], cylinder);
	parse_orientation_cylinder(tokens[2], cylinder);
	parse_color_cylinder(tokens[3], cylinder);
	parse_diameter_cylinder(tokens[4], cylinder);
	parse_height_cylinder(tokens[5], cylinder);

	return (cylinder);
}
