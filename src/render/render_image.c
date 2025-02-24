/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:13:34 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/24 22:24:41 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int			i;
	int			j;
	uint32_t	color;
	t_vec3		ray;

	i = 0;
	j = 0;
	while (j < WIN_HEIGHT)
	{
		while (i < WIN_WIDTH)
		{
			ray.z = j * 100 / WIN_HEIGHT - 50;
			ray.y = i * 100 / WIN_WIDTH - 50;
			ray.x = tan(deg_to_rad(90 - (scene->camera.fov_rad / 2))) * 100;
			ray = vec3_normalize(ray);
			color = get_color(ray_cast(ray, scene->objects));
			mlx_put_pixel(img, i, j, color);
			i++;
		}
		i = 0;
		j++;
	}
}

