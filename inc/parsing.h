/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:50:57 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/14 17:27:04 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minirt.h"

void	parse_file(t_error *error, t_scene *scene, int ac, char **av);




/*parse camera*/
t_camera    parse_camera(char **tokens, t_scene *scene);
void	parse_view_point(char *input, t_camera *cam);
void	parse_orientation(char *input, t_camera *cam);
void    parse_fov_rad(char *input, t_camera *cam);

/*parse sphere*/
t_sphere	*parse_sphere(char **tokens, t_scene *scene);
void	parse_position_sphere(char *token, t_sphere *sphere);
void    parse_diameter_sphere(char *token, t_sphere *sphere);
void    parse_color_sphere(char *token, t_sphere *sphere);

/*parse light*/
t_light		parse_light(char **tokens, t_scene *scene);
void    parse_light_position(char *input, t_light *light);
void    parse_light_ratio(char *input, t_light *light);
void    parse_light_color(char *input, t_light *light);

/*parse plane*/
t_plane *parse_plane(char **tokens, t_scene *scene);
void    parse_position_plane(char *input, t_plane *plane);
void    parse_orientation_plane(char *input, t_plane *plane);
void    parse_color_plane(char *input, t_light *plane);

/*parse cylinder*/
t_cylinder  *parse_cylinder(char **tokens, t_scene *scene);
void    parse_position_cylinder(char *input, t_cylinder *cylinder);
void    parse_orientation_cylinder(char *input, t_cylinder cylinder);
void    parse_color_cylinder(char *input, t_cylinder cylinder);
void    parse_diameter_cylinder(char *input, t_cylinder *cylinder);
void    parse_height_cylinder(char *input, t_cylinder *cylinder);

/*parsing error check*/
bool    colors_error(char **color);
bool    orientation_error(t_vec3 *orientation);
bool    format_error(char **coordinates);

#endif
