/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:21:33 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/19 11:47:42 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parsing.h"

t_object	object_create(t_error *error, char *line)
{
	t_object_kind	kind;
	t_object		object;

	kind = get_object_kind(line);
	object = g_parse_object[kind](error, line);
	object.kind = kind;
	return (object);
}
