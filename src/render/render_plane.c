/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:11:13 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/25 17:20:13 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "scene.h"
#include "renderer.h"
#include "ft_list.h"
#include "vector_math.h"

int	is_disrupted(t_vec3 ray_hit, t_plane plane)
{
	(void)ray_hit;
	(void)plane;
	return (0);
}

t_ray	ray_cast_plane(t_vec3 ray, t_vec3 origin, t_plane plane)
{
	double	delta_ray;
	double	plane_distance;
	t_ray	ray_cast;

	plane.orientation = vec3_scale(plane.orientation, -1);
	plane.position = vec3_sub(plane.position, origin);
	delta_ray = vec3_project(plane.orientation, ray);
	plane_distance = vec3_project(plane.orientation, plane.position);
	ray_cast.magnitude = nan("");
	if (plane_distance == 0.0)
		return (ray_cast);
	ray_cast.magnitude = plane_distance / delta_ray;
	if (ray_cast.magnitude < 0 || delta_ray < 0)
	{
		ray_cast.magnitude = nan("");
		return (ray_cast);
	}
	ray_cast.normal = vec3_scale(plane.orientation, -1);
	ray_cast.color = plane.color;
	plane.position = vec3_add(plane.position, origin);
	if (is_disrupted(ray_cast.hit, plane))
		ray_cast.color = scale_color(ray_cast.color, 0.5);
	return (ray_cast);
}
