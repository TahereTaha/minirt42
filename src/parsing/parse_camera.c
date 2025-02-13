/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:12:23 by rgiambon          #+#    #+#             */
/*   Updated: 2025/02/13 12:36:19 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(arry[i]);
	free(array);
}

int	ft_arraylen(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

bool	direction_error(t_vec3 *direction)
{
	if (direction->x > 1 || direction->x < -1)
		return (true);
	if (direction->y > 1 || direction->y < -1)
		return (true);
	if (direction->z > 1 || direction->z < -1)
		return (true);
	return (false);
}

void	parse_direction(char *input, t_camera *cam)
{
	char	**coordinates;

	coordinates = ft_split(input, ",");
	if (!coordinates)
		/*exit malloc error*/
	if (check_error_format(coordinates))
		/*exit formatt error*/
	cam->direction->x = ft_atof(coordinates[0]);
	cam->direction->y = ft_atof(coordinates[1]);
	cam->direction->z = ft_atof(coordinates[2]);
	if (direction_error(cam->direction))
		/*exit direction error*/
	free_array(coordinates);	

}

bool	format_error(char **coordinates)
{
	int	i;

	i = 0;
	if (ft_arraylen(coordinates) != 3)
		return (1);
	while (coordinates[i])
	{
		if (!ft_isfloat(coordinates[i]) || /*float overflow*/)
			return (1);
		i++;
	}
	return (0);
}

void	parse_origin(char *input, t_camera *cam)
{
	char	**coordinates;
	
	coordinates = ft_split(input, ",");
	if (!coordinates)
		/*exit with error malloc*/
	if (check_error_format(coordinates))
		/*exit with erro format*/
	cam->origin->x = ft_atof(coordinates[0]);
	cam->origin->y = ft_atof(coordinates[1]);
	cam->origin->z = ft_atof(coordinates[2]);

	free_array(coordinates);

}

void	parse_camera(char **tokens, t_scene *scene)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	if (!cam)
		/*malloc error exit*/
	/*if (args are not 4)
		exit with error message ;*/
	parse_origin(tokens[1], cam);
	parse_direction(tokens[2], cam);
	parse_fov(tokens[3], cam);
	
	scene->camera = cam;


}
