/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:13:34 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/26 15:13:57 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include "render_image.h"
#include "numbers.h"
#include "math.h"
#include "minirt.h"
#include "renderer.h"
#include "error_managment.h"
#include "MLX42/MLX42.h"

#include <time.h>

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

void	*child_tread(t_render_child *ptr)
{
	double		i;
	double		j;
	uint32_t	color;
	t_vec3		ray;

	i = 0.0;
	j = LINE_HEIGHT * ptr->index;
	while (j < LINE_HEIGHT * (ptr->index + 1))
	{
		while (i < WIN_WIDTH)
		{
			ray.z = (j * 100.0 / WIN_HEIGHT - 50.0) * -1.0;
			ray.y = i * 100.0 / WIN_WIDTH - 50.0;
			ray.x = tan(deg_to_rad(90.0 - (ptr->sc->camera.fov_rad / 2.0))) \
			* 50.0;
			ray = vec3_normalize(ray);
			color = get_color(ray_cast(ray, ptr->sc));
			mlx_put_pixel(ptr->img, i, j, color);
			i++;
		}
		i = 0.0;
		j++;
	}
	return (NULL);
}

void	render_image(mlx_image_t *img, t_scene *scene)
{
	t_render_child	render_childs[(int)TREAD_COUNT];
	pthread_t		treads[(int)TREAD_COUNT];
	int				i;
	clock_t begin = clock();

	i = 0;
	while (i < TREAD_COUNT)
	{
		render_childs[i].img = img;
		render_childs[i].sc = scene;
		render_childs[i].index = i;
		pthread_create(&(treads[i]), NULL, (t_void_ptr_fn)child_tread, &(render_childs[i]));
		i++;
	}
	i = 0;
	while (i < TREAD_COUNT)
	{
		pthread_join(treads[i], NULL);
		i++;
	}
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;	
	printf("%f\n", time_spent);
}
