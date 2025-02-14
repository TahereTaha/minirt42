/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:12:23 by rgiambon          #+#    #+#             */
/*   Updated: 2025/02/14 17:21:50 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

void	parse_fov_rad(char *input, t_camera *cam)
{
	if (!ft_isint(input) || ft_isintoverflow(input))
		/*error*/
	if (ft_atoi(input) < 0 || ft_atoi(input) > 180)
		/*error*/
	cam->fov_rad = ft_atoi(input);

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
	parse_view_point(tokens[1], &cam);
	parse_orientation(tokens[2], &cam);
	parse_fov_rad(tokens[3], &cam);
	
	return (cam);
}
