/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:39:00 by rgiambon          #+#    #+#             */
/*   Updated: 2025/02/13 12:39:02 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	parse_brightness(char *input)
{
	
}

void	parse_origin(char *input, t_light *light)
{
	char	**coordinates;
	
	coordinates = ft_split(input, ",");
	if (!coordinates)
		/*exit with error malloc*/
	if (check_error_format(coordinates))
		/*exit with erro format*/
	light->pov->x = ft_atof(coordinates[0]);
	light->pov->y = ft_atof(coordinates[1]);
	light->pov->z = ft_atof(coordinates[2]);

	free_array(coordinates);

}

void	parse_light(char **tokens, t_scene *scene)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		/*error malloc*/
	parse_pov(tokens[1]);
	parse_brightness(tokens[2]);
	parse_colors(tokens[3]);

	scene->light = light;
}
