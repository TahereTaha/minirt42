/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:09:56 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/08 10:51:18 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "error_managment.h"
# include "ft_list.h"
# include "scene.h"
# include "vector_math.h"
# include "MLX42/MLX42.h"

# define ALPHA	0.00000001

void		render_image_to_window(t_error *error, t_scene *scene);

void		render_image(mlx_image_t *img, t_scene *scene);

t_color		ray_cast(t_vec3 ray, t_scene *scene);

typedef struct s_ray
{
	t_color	color;
	double	magnitude;
	t_vec3	hit;
	t_vec3	normal;
}	t_ray;

t_ray		ray_cast_plane(t_vec3 ray, t_vec3 origin, t_plane plane);
t_ray		ray_cast_sphere(t_vec3 ray, t_vec3 origin, t_sphere sphere);
t_ray		ray_cast_cylinder(t_vec3 ray, t_vec3 origin, t_cylinder *cylinder);

t_ray		ray_cast_object(t_vec3 ray, t_vec3 origin, t_object *object);
t_color		light_point(t_ray ray_cast, t_scene *scene);
int			is_light_visible(t_light light, t_ray hit_point, t_list *objects);

t_color		get_ambient_light(t_ambient_light ambient_light);
t_color		get_difuse_light(t_scene *scene, t_ray hit_point);
t_color		get_phong_shine(t_scene *scene, t_ray hit_point);

t_color		scale_color(t_color color, double scalar);
t_color		add_color(t_color color1, t_color color2);
t_color		light_color(t_color color, t_color light);

double		intersect_top_cap(t_vec3 ray, t_vec3 origin, \
t_cylinder	*cylinder, double radius);
double		intersect_bottom_cap(t_vec3 ray, t_vec3 origin, \
t_cylinder *cylinder, double radius);
int			solve_quadratic(double *coefficients, double *roots);
double		get_closest_positive_t(double t1, double t2);
t_ray		ray_cast_cone(t_vec3 ray, t_vec3 origin, t_cone *cone);

int			is_plane_disrupted(t_vec3 ray_hit, t_plane plane);
t_vec3		is_plane_bump_map(t_vec3 ray_hit, t_plane plane);
#endif
