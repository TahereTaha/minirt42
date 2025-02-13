/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:12:12 by rgiambon          #+#    #+#             */
/*   Updated: 2025/02/13 13:15:24 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

bool	colors_error(char **color)
{
	int	i;

	i = 0;
	if (ft_arraylen(color) != 3)
		return (1);
	while (color[i])
	{
		/*check if int ?*/
		if (ft_atoi(color[i]) < 0 || ft_atoi(color[i]) > 255)
			return (1);
		i++;
	}
	return (0);
}

void	parse_color(char *token, t_sphere *sphere)
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

void	parse_diameter(char *token, t_sphere *sphere)
{
	/*error check*/

	if (ft_isfloat(token))
		if (!is_floatoverflow(token))
			sphere->diameter = ft_atof(token);
	else
		if (!is_intoverflow(token))
			sphere->diameter = ft_atoi(token);
}

void	parse_position(char *token, t_sphere *sphere)
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
	parse_position(tokens[0], sphere);
	parse_diameter(tokens[1]);
	parse_color(tokens[2]);

	return (sphere);
}
