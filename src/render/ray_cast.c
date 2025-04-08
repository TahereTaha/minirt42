/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:20:57 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/08 10:29:50 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "scene.h"
#include "renderer.h"
#include "ft_list.h"

t_vec3	null_vec(void)
{
	t_vec3	vec;

	vec.x = 0;
	vec.y = 0;
	vec.z = 0;
	return (vec);
}

t_ray	ray_cast_object(t_vec3 ray, t_vec3 origin, t_object *object)
{
	t_ray	ray_cast;

	ray_cast.magnitude = nan("");
	ray_cast.color = (t_color){0, 0, 0};
	if (object->kind == PLANE)
		ray_cast = ray_cast_plane(ray, origin, *(t_plane *)object);
	else if (object->kind == SPHERE)
		ray_cast = ray_cast_sphere(ray, origin, *(t_sphere *)object);
	else if (object->kind == CYLINDER)
		ray_cast = ray_cast_cylinder(ray, origin, (t_cylinder *)object);
	else if (object->kind == CONE)
		ray_cast = ray_cast_cone(ray, origin, (t_cone *)object);
	ray_cast.magnitude -= ALPHA;
	if (!isnan(ray_cast.magnitude))
		ray_cast.hit = vec3_scale(ray, ray_cast.magnitude);
	return (ray_cast);
}

int	ray_is_closer(t_ray ray_cast, t_ray new_ray_cast)
{
	if (isnan(new_ray_cast.magnitude))
		return (0);
	if (isnan(ray_cast.magnitude))
		return (1);
	if (new_ray_cast.magnitude < ray_cast.magnitude)
		return (1);
	return (0);
}

t_color	ray_cast(t_vec3 ray, t_scene *scene)
{
	t_ray	ray_cast;
	t_ray	new_ray_cast;
	t_list	*node;

	node = scene->objects;
	ray_cast.magnitude = nan("");
	ray_cast.color = (t_color){0, 0, 0};
	while (node)
	{
		new_ray_cast = ray_cast_object(ray, null_vec(), \
		(t_object *)node->content);
		if (ray_is_closer(ray_cast, new_ray_cast))
			ray_cast = new_ray_cast;
		node = node->next;
	}
	ray_cast.color = light_point(ray_cast, scene);
	return (ray_cast.color);
}
