/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:36:35 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/02 11:39:30 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>
# include "scene.h"
# include "error_managment.h"
# include "vector_math.h"

t_vec3		parse_vector(char **vec_str);

void		check_argument(t_error *error, int ac, char **av);
void		parse_file(t_error *error, t_scene *scene, int ac, char **av);
void		parse_line(t_error *error, t_scene *scene, char *line);

void		parse_blank(void);
t_object	parse_ambient_light(t_error *error, char *line);
t_object	parse_camera(t_error *error, char *line);
t_object	parse_light(t_error *error, char *line);
t_object	parse_sphere(t_error *error, char *line);
t_object	parse_plane(t_error *error, char *line);
t_object	parse_cylinder(t_error *error, char *line);
t_object	parse_cone(t_error *error, char *line);
t_object	parse_comment(t_error *error, char *line);
t_object	parse_unexistent(t_error *error, char *line);

typedef t_object			(*t_parse_object)(t_error *error, char *line);

static const t_parse_object	g_parse_object[] = \
	{\
	(t_parse_object) parse_blank, \
	(t_parse_object) parse_ambient_light, \
	(t_parse_object) parse_camera, \
	(t_parse_object) parse_light, \
	(t_parse_object) parse_sphere, \
	(t_parse_object) parse_plane, \
	(t_parse_object) parse_cylinder, \
	(t_parse_object) parse_cone, \
	(t_parse_object) parse_comment, \
	(t_parse_object) parse_unexistent, \
	(t_parse_object) NULL \
};

// Parsing error check functions
int			color_error(t_color *color);
int			orientation_error(t_vec3 *orientation);
int			format_error(char **coordinates);

// Camera parsing functions
void		parse_view_point(t_error *error, char *token, t_camera *cam);
void		parse_orientation(t_error *error, char *token, t_camera *cam);
void		parse_fov_rad(t_error *error, char *token, t_camera *cam);

// Sphere parsing functions
void		parse_position_sphere(t_error *error, char *token, t_sphere *sp);
void		parse_diameter_sphere(t_error *error, char *token, t_sphere *sp);
void		parse_color_sphere(t_error *error, char *token, t_sphere *sp);

// Light parsing functions
void		parse_light_position(t_error *error, char *token, t_light *light);
void		parse_light_ratio(t_error *error, char *token, t_light *light);
void		parse_light_color(t_error *error, char *token, t_light *light);

// Plane parsing functions
void		parse_position_plane(t_error *error, char *token, t_plane *plane);
void		parse_orientation_plane(t_error *error, char *token, t_plane *pl);
void		parse_color_plane(t_error *error, char *token, t_plane *plane);

// Cylinder parsing functions
void		parse_position_cylinder(t_error *err, char *token, t_cylinder *cy);
void		parse_orientation_cylinder(t_error *err, char *tk, t_cylinder *cy);
void		parse_color_cylinder(t_error *error, char *token, t_cylinder *cy);
void		parse_diameter_cylinder(t_error *err, char *token, t_cylinder *cy);
void		parse_height_cylinder(t_error *error, char *token, t_cylinder *cy);

// Utils
int			ft_arraylen(char **array);
void		free_array(char **array);

//	preprocecing
void		preproces(t_scene *scene);
void		move_camera_to_center(t_scene *scene);
void		rotate_word(t_scene *scene);
void		normalize_scene(t_scene *scene);
void		rotate_cylinder(t_cylinder *object, t_mtx3 mtx);
void		rotate_sphere(t_sphere *object, t_mtx3 mtx);
void		rotate_plane(t_plane *object, t_mtx3 mtx);
t_mtx3		make_rotation_mtx_z(t_vec3 direction);
t_mtx3		make_rotation_mtx_y(t_vec3 direction);

t_disrupt	get_disruption(t_error, char *token);
t_bump_map	get_bump_map(t_error, char *token);

// parse cone
void    parse_color_cone(t_error *error, char *token, t_cone *co);
t_object    parse_cone(t_error *error, char *line);
#endif
