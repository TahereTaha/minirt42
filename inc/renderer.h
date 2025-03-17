/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:09:56 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/15 14:05:19 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

#include "error_managment.h"
#include "ft_list.h"
#include "scene.h"
#include "vector_math.h"
#include "MLX42/MLX42.h"

void	render_image_to_window(t_error *error, t_scene *scene);

void	render_image(mlx_image_t *img, t_scene *scene);

t_color	ray_cast(t_vec3 ray, t_list *scene);

typedef struct s_ray
{
	t_color	color;
	double	magnitude;
}	t_ray;

t_ray	ray_cast_plane(t_vec3 ray, t_plane *plane);
t_ray	ray_cast_sphere(t_vec3 ray, t_sphere *sphere);
t_ray	ray_cast_cylinder(t_vec3 ray, t_vec3 ray_origin, t_cylinder *cylinder);

#endif
