/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:13:34 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/08 11:07:22 by tatahere         ###   ########.fr       */
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

#include <sys/time.h>

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

void	*child_thread(t_render_child *ptr)
{
	double		i;
	double		j;
	uint32_t	color;
	t_vec3		ray;

	i = 0.0;
	j = ptr->index * LINE_HEIGHT;
	while (j < (ptr->index + 1) * LINE_HEIGHT)
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
		j += 1;
	}
	return (NULL);
}

size_t	get_time_ms(struct timeval time)
{
	size_t	time_ms;

	time_ms = 0;
	time_ms += time.tv_usec / 1000;
	time_ms += (time.tv_sec % 100000) * 1000;
	return (time_ms);
}

void	print_time_ms(struct timeval start, struct timeval end)
{
	printf("this took %zums to render.\n", \
	get_time_ms(end) - get_time_ms(start));
	printf("the rendering is done\n");
}

void	render_image(mlx_image_t *img, t_scene *scene)
{
	t_render_child	render_childs[(int)THREAD_COUNT];
	pthread_t		treads[(int)THREAD_COUNT];
	int				i;
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
	i = 0;
	while (i < THREAD_COUNT)
	{
		render_childs[i].img = img;
		render_childs[i].sc = scene;
		render_childs[i].index = i;
		pthread_create(&(treads[i]), NULL, \
		(t_void_ptr_fn)child_thread, &(render_childs[i]));
		i++;
	}
	i = 0;
	while (i < THREAD_COUNT)
	{
		pthread_join(treads[i], NULL);
		i++;
	}
	gettimeofday(&end, NULL);
	print_time_ms(start, end);
}
