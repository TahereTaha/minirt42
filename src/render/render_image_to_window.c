/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image_to_window.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:13:27 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/26 10:34:45 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "error_managment.h"
#include "minirt.h"
#include "renderer.h"
#include "MLX42/MLX42.h"

mlx_t	*make_window_and_img(t_error *error, t_scene *scene)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "minirt42", 0);
	if (!mlx)
	{
		error_set(error, mlx_errno);
		return (NULL);
	}
	img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!img)
	{
		mlx_terminate(mlx);
		error_set(error, mlx_errno);
		return (NULL);
	}
	(void)scene;
	render_image(img, scene);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
	{
		mlx_terminate(mlx);
		error_set(error, mlx_errno);
		return (NULL);
	}
	return (mlx);
}

void	render_image_to_window(t_error *error, t_scene *scene)
{
	mlx_t	*mlx;

	if (error->errnum)
		return ;
	mlx = make_window_and_img(error, scene);
	if (error->errnum)
		return ;
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
