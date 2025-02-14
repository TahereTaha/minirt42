/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:37:20 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/14 18:16:53 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "minirt.h"
#include "error_managment.h"

t_scene	*make_scene(t_error *error)
{
	t_scene	*scene;
	
	scene = scene_create();
	if (!scene)
	{
		error_set(error, errno);
		error_msg_append(error, "miniRT: ", 0);
		error_manage(error);
	}
	return (scene);
}

int	main(void)
{
	t_error	*error;
	t_scene	*scene;

	error = error_create();
	error_clear(error);
	scene = make_scene(error);
	scene_destroy(scene);
	error_destroy(error);
	return (0);
}
