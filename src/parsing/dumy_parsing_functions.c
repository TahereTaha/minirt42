/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumy_parsing_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:22:07 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/22 18:12:10 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_errors.h"
#include "error_managment.h"
#include "parsing.h"

void			parse_blank(void)
{
	return ;
}

t_object	get_object(t_object object)
{
	return (object);
}

/*
t_object	parse_ambient_light(t_error *error, char *line)
{
	(void)error;
	(void)line;
	t_object	thing;
	thing.kind = 0;
	return (*((t_object *)&thing));
}
t_object	parse_camera(t_error *error, char *line)
{
	(void)error;
	(void)line;
	t_object	aux;
	t_camera	*thing;

	thing = (t_camera *)&aux;
	thing->kind = 0;
	return (aux);
}

t_object	parse_light(t_error *error, char *line)
{
	(void)error;
	(void)line;
	t_object	thing;
	thing.kind = 0;
	return (*((t_object *)&thing));
}

t_object	parse_sphere(t_error *error, char *line)
{
	(void)error;
	(void)line;
	t_sphere	thing;
	thing.kind = 0;
	return (*((t_object *)&thing));
}

t_object	parse_plane(t_error *error, char *line)
{
	(void)error;
	(void)line;
	t_object	thing;
	thing.kind = 0;
	return (*((t_object *)&thing));
}

t_object	parse_cylinder(t_error *error, char *line)
{
	(void)error;
	(void)line;
	t_object	thing;
	thing.kind = 0;
	return (*((t_object *)&thing));
}

*/
//	this suodent need the char *line but the calling convention needed to be right to left.
t_object	parse_unexistent(t_error *error, char *line)
{
	(void)line;
	error_set(error, WRONG_OBJECT_IDENTIFIER);
	t_cylinder	thing;
	thing.kind = 0;
	return (*((t_object *)&thing));
}

