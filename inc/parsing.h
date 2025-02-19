/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:36:35 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/19 13:26:35 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>
# include "scene.h"
# include "error_managment.h"

void			check_argument(t_error *error, int ac, char **av);
void			parse_file(t_error *error, t_scene *scene, int ac, char **av);
void			parse_line(t_error *error, t_scene *scene, char *line);

void			parse_blank(void);
t_ambient_light	parse_ambient_light(t_error *error, char *line);
t_object		parse_camera(t_error *error, char *line);
t_object			parse_light(t_error *error, char *line);
t_sphere		parse_sphere(t_error *error, char *line);
t_plane			parse_plane(t_error *error, char *line);
t_cylinder		parse_cylinder(t_error *error, char *line);
t_object		parse_unexistent(t_error *error, char *line);

typedef t_object	(*t_parse_object)(t_error *error, char *line);

const static t_parse_object	g_parse_object[] = \
{\
	(t_parse_object) parse_blank, \
	(t_parse_object) parse_ambient_light, \
	(t_parse_object) parse_camera, \
	(t_parse_object) parse_light, \
	(t_parse_object) parse_sphere, \
	(t_parse_object) parse_plane, \
	(t_parse_object) parse_cylinder, \
	(t_parse_object) parse_unexistent, \
	(t_parse_object) NULL \
};

/*
//	parsing utils (momentary)
int	ft_arraylen(char **array);
void	free_array(char **array);


//	parse camera
t_camera    parse_camera(char **tokens, t_scene *scene);
void	parse_view_point(char *token, t_camera *cam);
void	parse_orientation(char *token, t_camera *cam);
void    parse_fov_rad(char *token, t_camera *cam);

//parse spherea
t_sphere	*parse_sphere(char **tokens, t_scene *scene);
void	parse_position_sphere(char *token, t_sphere *sphere);
void    parse_diameter_sphere(char *token, t_sphere *sphere);
void    parse_color_sphere(char *token, t_sphere *sphere);

//parse lighta
t_light		parse_light(char **tokens, t_scene *scene);
void    parse_light_position(char *token, t_light *light);
void    parse_light_ratio(char *token, t_light *light);
void    parse_light_color(char *token, t_light *light);

//parse planea
t_plane *parse_plane(char **tokens, t_scene *scene);
void    parse_position_plane(char *token, t_plane *plane);
void    parse_orientation_plane(char *token, t_plane *plane);
void    parse_color_plane(char *token, t_plane *plane);

//parse cylindera
t_cylinder  *parse_cylinder(char **tokens, t_scene *scene);
void    parse_position_cylinder(char *token, t_cylinder *cylinder);
void    parse_orientation_cylinder(char *token, t_cylinder *cylinder);
void    parse_color_cylinder(char *token, t_cylinder *cylinder);
void    parse_diameter_cylinder(char *token, t_cylinder *cylinder);
void    parse_height_cylinder(char *token, t_cylinder *cylinder);

//parsing error checka
bool    colors_error(char **color);
bool    orientation_error(t_vec3 *orientation);
bool    format_error(char **coordinates);
*/

#endif
