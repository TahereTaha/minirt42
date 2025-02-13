/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:50:57 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/13 13:25:44 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

void	parse_file(t_error *error, t_cene *cene, int ac, char **av);


t_sphere	*parse_sphere(char **tokens, t_scene *scene);
t_light		parse_light(char **tokens, t_scene *scene);
t_camera	parse_camera(char **tokens, t_scene *scene);

#endif
