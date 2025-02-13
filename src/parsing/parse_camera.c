/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:12:23 by rgiambon          #+#    #+#             */
/*   Updated: 2025/02/13 13:10:36 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

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

bool	orientation_error(t_vec3 *orientation)
{
	if (direction->x > 1 || direction->x < -1)
		return (true);
	if (direction->y > 1 || direction->y < -1)
		return (true);
	if (direction->z > 1 || direction->z < -1)
		return (true);
	return (false);
}

void	parse_orientation(char *input, t_camera *cam)
{
	char	**coordinates;

	coordinates = ft_split(input, ",");
	if (!coordinates)
		/*exit malloc error*/
	if (check_error_format(coordinates))
		/*exit formatt error*/
	cam->orientation->x = ft_atof(coordinates[0]);
	cam->orientation->y = ft_atof(coordinates[1]);
	cam->orientation->z = ft_atof(coordinates[2]);
	if (orientation_error(cam->orientation))
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

void	parse_view_point(char *input, t_camera *cam)
{
	char	**coordinates;
	
	coordinates = ft_split(input, ",");
	if (!coordinates)
		/*exit with error malloc*/
	if (check_error_format(coordinates))
		/*exit with erro format*/
	cam->view_point->x = ft_atof(coordinates[0]);
	cam->view_point->y = ft_atof(coordinates[1]);
	cam->view_point->z = ft_atof(coordinates[2]);

	free_array(coordinates);

}

t_camera	parse_camera(char **tokens, t_scene *scene)
{
	t_camera	cam;

	if (ft_arraylen(tokens) != 4)
		/*error too few args*/
	cam = malloc(sizeof(t_camera));
	if (!cam)
		/*malloc error exit*/
	parse_view_point(tokens[1], &cam);
	parse_orientation(tokens[2], &cam);
	parse_fov_rad(tokens[3], &cam);
	
	return (cam);
}
