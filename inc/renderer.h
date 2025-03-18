/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:09:56 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/18 06:48:48 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

#include "error_managment.h"
#include "ft_list.h"
#include "scene.h"
#include "vector_math.h"
#include "MLX42/MLX42.h"

# define ALPHA	0.00000001

void	render_image_to_window(t_error *error, t_scene *scene);

void	render_image(mlx_image_t *img, t_scene *scene);

t_color	ray_cast(t_vec3 ray, t_scene *scene);

typedef struct s_ray
{
	t_color	color;
	double	magnitude;
	t_vec3	hit;
	t_vec3	normal;
}	t_ray;

t_ray	ray_cast_plane(t_vec3 ray, t_vec3 origin, t_plane plane);
t_ray	ray_cast_sphere(t_vec3 ray, t_vec3 origin, t_sphere sphere);
t_ray	ray_cast_cylinder(t_vec3 ray, t_vec3 origin, t_cylinder *cylinder);

t_ray	ray_cast_object(t_vec3 ray, t_vec3 origin, t_object *object);
t_color	light_point(t_ray ray_cast, t_light light, t_list *objets);

#endif
