/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:36:35 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/10 13:55:15 by tatahere         ###   ########.fr       */
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
t_object		parse_ambient_light(t_error *error, char *line);
t_object		parse_camera(t_error *error, char *line);
t_object		parse_light(t_error *error, char *line);
t_object		parse_sphere(t_error *error, char *line);
t_object		parse_plane(t_error *error, char *line);
t_object		parse_cylinder(t_error *error, char *line);
t_object		parse_unexistent(t_error *error, char *line);

typedef t_object	(*t_parse_object)(t_error *error, char *line);

static const t_parse_object	g_parse_object[] = \
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

// Parsing error check functions
int		color_error(t_color *color);
int		orientation_error(t_vec3 *orientation);
int		format_error(char **coordinates);

// Camera parsing functions
void	parse_view_point(t_error *error, char *token, t_camera *cam);
void	parse_orientation(t_error *error, char *token, t_camera *cam);
void	parse_fov_rad(t_error *error, char *token, t_camera *cam);

// Sphere parsing functions
void	parse_position_sphere(t_error *error, char *token, t_sphere *sphere);
void	parse_diameter_sphere(t_error *error, char *token, t_sphere *sphere);
void	parse_color_sphere(t_error *error, char *token, t_sphere *sphere);

// Light parsing functions
void	parse_light_position(t_error *error, char *token, t_light *light);
void	parse_light_ratio(t_error *error, char *token, t_light *light);
void	parse_light_color(t_error *error, char *token, t_light *light);

// Plane parsing functions
void	parse_position_plane(t_error *error, char *token, t_plane *plane);
void	parse_orientation_plane(t_error *error, char *token, t_plane *plane);
void	parse_color_plane(t_error *error, char *token, t_plane *plane);

// Cylinder parsing functions
void	parse_position_cylinder(t_error *error, char *token, t_cylinder *cylinder);
void	parse_orientation_cylinder(t_error *error, char *token, t_cylinder *cylinder);
void	parse_color_cylinder(t_error *error, char *token, t_cylinder *cylinder);
void	parse_diameter_cylinder(t_error *error, char *token, t_cylinder *cylinder);
void	parse_height_cylinder(t_error *error, char *token, t_cylinder *cylinder);

// Utils
int		ft_arraylen(char **array);
void	free_array(char **array);

//	preprocecing
void	preproces(t_scene *scene);
void	move_camera_to_center(t_scene *scene);
void	rotate_word(t_scene *scene);
void	normalize_scene(t_scene *scene);

#endif
