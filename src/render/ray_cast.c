/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:20:57 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/28 12:50:31 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "scene.h"
#include "renderer.h"
#include "ft_list.h"

double	ft_abs(double num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

//	delta ray is how much the ray is geting close to the plane.
t_ray	ray_cast_plane(t_vec3 ray, t_plane *plane)
{
	double	delta_ray;
	double	plane_distance;
	t_ray	ray_cast;

	//	fix the normals of the planes. this shoud be in the parsing side of thing.
	
	//	normal function code.
	delta_ray = vec3_dot_product(plane->orientation, ray) / 
		vec3_get_magnitude(plane->orientation);

	plane_distance = vec3_dot_product(plane->orientation, plane->position) / 
		vec3_get_magnitude(plane->orientation);

	ray_cast.color = plane->color;
	ray_cast.magnitude = plane_distance / delta_ray;
	if (ray_cast.magnitude < 0 || delta_ray < 0)
		ray_cast.magnitude = nan("");
	return (ray_cast);
}



t_ray	ray_cast_object(t_vec3 ray, t_object *object)
{
	t_ray	ray_cast;

	
	if (object->kind == PLANE)
		ray_cast = ray_cast_plane(ray, (t_plane *)object);
	else if (object->kind == SPHERE)
		ray_cast = ray_cast_sphere(ray, (t_sphere *)object);
	/*
	else return no intersection 
	{
		ray_cast.magnitude = 1000000000;
		ray_cast.color = (t_color){0, 0, 0};
	}*/
	return (ray_cast);
}

t_color	ray_cast(t_vec3 ray, t_list *objects)
{
	t_ray	ray_cast;
	t_ray	new_ray_cast;

	ray_cast.magnitude = nan("");
	while (objects)
	{
		new_ray_cast = ray_cast_object(ray, (t_object *)objects->content);
		if (isnan(ray_cast.magnitude) || (!isnan(new_ray_cast.magnitude) && new_ray_cast.magnitude < ray_cast.magnitude))
			ray_cast = new_ray_cast;
		objects = objects->next;
	}
	return (ray_cast.color);
}
