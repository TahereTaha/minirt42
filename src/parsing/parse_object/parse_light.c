/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:39:00 by rgiambon          #+#    #+#             */
/*   Updated: 2025/02/13 14:16:32 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minirt.h"
#include "../../inc/parsing.h"

void	parse_light_color(char *input, t_light *light)
{
	char	**color;

	color = ft_split(token, ",")
	if (!color)
		/*malloc error*/
	if (colors_error(color))
		/*format error*/
	light->light_color->r = ft_atoi(color[0]); 
	light->light_color->g = ft_atoi(color[1]);
	light->light_color->b = ft_atoi(color[2]);

	free_array(color);
}


void	parse_light_ratio(char *input, t_light *light)
{
	if (!ft_isfloat(input) || ft_isfloatoverflow(input))
		/*error*/
	if (ft_atof(input) < 0.0 || ft_atof(input) > 1.0)
		/*error*/
	light->light_ratio = ft_atof(input);
}

void	parse_light_position(char *input, t_light *light)
{
	char	**coordinates;
	
	coordinates = ft_split(input, ",");
	if (!coordinates)
		/*exit with error malloc*/
	if (check_error_format(coordinates))
		/*exit with erro format*/
	light->position->x = ft_atof(coordinates[0]);
	light->position->y = ft_atof(coordinates[1]);
	light->position->z = ft_atof(coordinates[2]);

	free_array(coordinates);

}

t_light	parse_light(char **tokens, t_scene *scene)
{
	t_light	light;

	parse_light_position(tokens[1], &light);
	parse_light_ratio(tokens[2], &light);
	parse_light_color(tokens[3], &light);

	return (light);
}
