/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:20:57 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/24 22:27:06 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "renderer.h"
#include "ft_list.h"

//	delta ray is how much the ray is geting close to the plane.
t_ray	ray_cast_plane(t_vec3 ray, t_plane *plane)
{
	double	delta_ray;
	double	plane_distance;
	t_ray	ray_cast;

	delta_ray = vec3_dot_product(plane->orientation, ray) / \
				vec3_get_magnitude(plane->orientation);
	plane_distance = vec3_dot_product(plane->orientation, plane->position) / \
					vec3_get_magnitude(plane->orientation);
	ray_cast.color = plane->color;
	ray_cast.magnitude = plane_distance / delta_ray;
	return (ray_cast);
}

t_ray	ray_cast_object(t_vec3 ray, t_object *object)
{
	t_ray	ray_cast;

	//	there will be some code to chose witch figure to use.
	ray_cast = ray_cast_plane(ray, (t_plane *)object);
	return (ray_cast);
}

t_color	ray_cast(t_vec3 ray, t_list *objects)
{
	t_ray	ray_cast;
	t_ray	new_ray_cast;

	ray_cast.magnitude = 1000000000;
	while (objects)
	{
		new_ray_cast = ray_cast_object(ray, (t_object *)objects->content);
		if (new_ray_cast.magnitude < ray_cast.magnitude)
			ray_cast = new_ray_cast;
		objects = objects->next;
	}
	return (ray_cast.color);
}
