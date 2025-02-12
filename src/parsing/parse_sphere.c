bool	colors_error(char **colors)
{
	int	i;

	i = 0;
	if (ft_arraylen(colors) != 3)
		return (1);
	while (colors[i])
	{
		/*check if int ?*/
		if (ft_atoi(colors[i]) < 0 || ft_atoi(color[i]) > 255)
			return (1);
		i++;
	}
	return (0);
}

void	parse_colors(char *token, t_sphere *sphere)
{
	char	**colors;

	colors = ft_split(token, ",")
	if (!colors)
		/*malloc error*/
	if (colors_error(colors))
		/*format error*/
	sphere->colors->r = ft_atoi(colors[0]); 
	sphere->colors->g = ft_atoi(colors[1]);
	sphere->colors->b = ft_atoi(colors[2]);

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

void	parse_center(char *token, t_sphere *sphere)
{
	char **coordinates;

	coordinates = ft_split(token, ",");
	if (!coordinates)
		/*error malloc*/
	if (format_error(coordinates))
		/*error format*/
	sphere->center->x = ft_atof(tokens[0]);
	sphere->center->y = ft_atof(tokens[1]);
	sphere->center->z = ft_atof(tokens[2]);

	free_array(coordinates);
}

void    parse_sphere(char **tokens, t_scene *scene)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		/*malloc error*/
	parse_center(tokens[0]);
	parse_diameter(tokens[1]);
	parse_colors(tokens[2]);

	/*add node to the list*/
}
