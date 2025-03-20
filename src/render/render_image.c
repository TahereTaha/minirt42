/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:13:34 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/20 10:59:21 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "numbers.h"
#include "math.h"
#include "minirt.h"
#include "renderer.h"
#include "error_managment.h"
#include "MLX42/MLX42.h"

uint32_t	get_color(t_color color)
{
	uint32_t	new_color;

	new_color = 0;
	new_color |= 255;
	new_color |= color.b << 8;
	new_color |= color.g << 16;
	new_color |= color.r << 24;
	return (new_color);
}

void		render_image(mlx_image_t *img, t_scene *scene)
{
	double		i;
	double		j;
	uint32_t	color;
	t_color		our_color;
	t_vec3		ray;

	i = 0.0;
	j = 0.0;
	while (j < WIN_HEIGHT)
	{
		while (i < WIN_WIDTH)
		{
			ray.z = (j * 100.0 / WIN_HEIGHT - 50.0) *  -1.0;
			//ray.z = (double)((double)(j * 100) / (double)WIN_HEIGHT - (double)50) * (double) -1;
			ray.y = i * 100.0 / WIN_WIDTH - 50.0;
			//ray.y = (double)(i * 100) / (double)WIN_WIDTH - (double)50;
			ray.x = tan(deg_to_rad(90.0 - (scene->camera.fov_rad / 2.0))) * 50.0;
			ray = vec3_normalize(ray);
			our_color = ray_cast(ray, scene);
			color = get_color(our_color);
			mlx_put_pixel(img, i, j, color);
			i++;
		}
		i = 0.0;
		j++;
	}
	printf("the thing is done.\n");
}
