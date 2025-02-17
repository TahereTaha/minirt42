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
#include "parsing.h"

//add this two functions to utils of some kind
void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(arry[i]);
		i++;
	}
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


//can it also be a float???
void	parse_fov_rad(char *token, t_camera *cam)
{
	if (!ft_isint(token) || ft_isintoverflow(token))
	{
		printf("ERROR: format/overflow\n");
		exit ();
	}
	if (ft_atoi(token) < 0 || ft_atoi(token) > 180)
	{
		printf("ERROR: range\n");
		exit ();
	}
	cam->fov_rad = ft_atoi(token);

}

void	parse_orientation(char *token, t_camera *cam)
{
	char	**coordinates;

	coordinates = ft_split(token, ',');
	if (!coordinates)
	{
		printf("ERROR: malloc\n");
		exit ();
	}
	if (format_error(coordinates))
	{
		printf("ERROR: format\n");
		exit ();
	}
	cam->orientation.x = ft_atof(coordinates[0]);
	cam->orientation.y = ft_atof(coordinates[1]);
	cam->orientation.z = ft_atof(coordinates[2]);
	if (orientation_error(cam->orientation))
	{
		printf("ERROR: range\n");
		exit ();
	}
	free_array(coordinates);	

}

void	parse_view_point(char *token, t_camera *cam)
{
	char	**coordinates;
	
	coordinates = ft_split(token, ',');
	if (!coordinates)
	{
		printf("ERROR: malloc\n");
		exit ();
	}
	if (format_error(coordinates))
	{
		printf("ERROR: format\n");
		exit ();
	}
	cam->view_point.x = ft_atof(coordinates[0]);
	cam->view_point.y = ft_atof(coordinates[1]);
	cam->view_point.z = ft_atof(coordinates[2]);

	free_array(coordinates);

}

t_camera	parse_camera(char **tokens, t_scene *scene)
{
	t_camera	cam;

	if (ft_arraylen(tokens) != 4)
	{
		printf("ERROR: wrong args\n");
		exit();
	}
	parse_view_point(tokens[1], &cam);
	parse_orientation(tokens[2], &cam);
	parse_fov_rad(tokens[3], &cam);
	
	(void)scene;
	
	return (cam);
}
