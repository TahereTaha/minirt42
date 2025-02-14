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

	colors = ft_split(token, ",")
	if (!colors)
		/*malloc error*/
	if (colors_error(colors))
		/*format error*/
	sphere->color->r = ft_atoi(colors[0]); 
	sphere->color->g = ft_atoi(colors[1]);
	sphere->color->b = ft_atoi(colors[2]);

	free_array(colors);
}

void	parse_diameter_sphere(char *token, t_sphere *sphere)
{
	/*error check*/

	if (ft_isfloat(token))
		if (!is_floatoverflow(token))
			sphere->diameter = ft_atof(token);
	else
		if (!is_intoverflow(token))
			sphere->diameter = ft_atoi(token);
}

void	parse_position_sphere(char *token, t_sphere *sphere)
{
	char **coordinates;

	coordinates = ft_split(token, ",");
	if (!coordinates)
		/*error malloc*/
	if (format_error(coordinates))
		/*error format*/
	sphere->position->x = ft_atof(tokens[0]);
	sphere->position->y = ft_atof(tokens[1]);
	sphere->position->z = ft_atof(tokens[2]);

	free_array(coordinates);
}

t_sphere	*parse_sphere(char **tokens, t_scene *scene)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		/*malloc error*/
	parse_position_sphere(tokens[0], sphere);
	parse_diameter_sphere(tokens[1]);
	parse_color_sphere(tokens[2]);

	return (sphere);
}
