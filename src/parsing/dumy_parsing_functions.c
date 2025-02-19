/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumy_parsing_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:22:07 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/19 12:29:40 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_errors.h"
#include "error_managment.h"
#include "parsing.h"

void			parse_blank(void)
{
	return ;
}

t_ambient_light	parse_ambient_light(t_error *error, char *line)
{
	(void)error;
	(void)line;
	t_ambient_light	thing;
	thing.kind = 0;
	return (thing);
}

t_camera		parse_camera(t_error *error, char *line)
{
	(void)error;
	(void)line;
	t_camera	thing;
	thing.kind = 0;
	return (thing);
}

t_light			parse_light(t_error *error, char *line)
{
	(void)error;
	(void)line;
	t_light	thing;
	thing.kind = 0;
	return (thing);
}

t_sphere		parse_sphere(t_error *error, char *line)
{
	(void)error;
	(void)line;
	t_sphere	thing;
	thing.kind = 0;
	return (thing);
}

t_plane			parse_plane(t_error *error, char *line)
{
	(void)error;
	(void)line;
	t_plane	thing;
	thing.kind = 0;
	return (thing);
}

t_cylinder		parse_cylinder(t_error *error, char *line)
{
	(void)error;
	(void)line;
	t_cylinder	thing;
	thing.kind = 0;
	return (thing);
}

//	this suodent need the char *line but the calling convention needed to be right to left.
t_object	parse_unexistent(t_error *error, char *line)
{
	(void)line;
	error_set(error, WRONG_OBJECT_IDENTIFIER);
}

