/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:20:57 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/17 14:12:26 by tatahere         ###   ########.fr       */
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

	delta_ray = vec3_project(plane->orientation, ray); 

	plane_distance = vec3_project(plane->orientation, plane->position); 
	ray_cast.magnitude = nan("");
	if (plane_distance == 0.0)
		return (ray_cast);

	ray_cast.magnitude = plane_distance / delta_ray;
	if (ray_cast.magnitude < 0 || delta_ray < 0)
	{
		ray_cast.magnitude = nan("");
		return (ray_cast);
	}
	ray_cast.color = plane->color;

	return (ray_cast);
}

//	this in another file

t_vec3	get_null_vector(void)
{
	t_vec3	vec;

	vec.x = 0;
	vec.y = 0;
	vec.z = 0;
	return (vec);
}

t_ray	ray_cast_object(t_vec3 ray, t_object *object)
{
	t_ray	ray_cast;

	ray_cast.magnitude = nan("");
	ray_cast.color = (t_color){0, 0, 0};
	if (object->kind == PLANE)
		ray_cast = ray_cast_plane(ray, (t_plane *)object);
	else if (object->kind == SPHERE)
		ray_cast = ray_cast_sphere(ray, (t_sphere *)object);
//	else if (object->kind == CYLINDER)
//		ray_cast = ray_cast_cylinder(ray, get_null_vector(), (t_cylinder *)object);
	return (ray_cast);
}

t_color	ray_cast(t_vec3 ray, t_list *objects)
{
	t_ray	ray_cast;
	t_ray	new_ray_cast;
	t_list	*node;

	node = objects;
	ray_cast.magnitude = nan("");
	ray_cast.color = (t_color){0, 0, 0};
	while (node)
	{
		new_ray_cast = ray_cast_object(ray, (t_object *)node->content);
		if (!isnan(new_ray_cast.magnitude) && new_ray_cast.magnitude < ray_cast.magnitude)
			ray_cast = new_ray_cast;
		node = node->next;
	}
	return (ray_cast.color);
}
