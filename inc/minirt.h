/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:28:41 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/12 13:16:26 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef	MINIRT_H
#define MINIRT_H

#include "vector_math.h"

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
}	t_colors;

typedef struct s_light
{
	vec3		pov;
	double		brightness;
	t_colors	colors;
}	t_light;

typedef	struct s_camera
{
	t_vec3	origin;
	t_vec3	direction;
	t_vec3	fov;
}	t_camera;

typedef struct s_sphere
{
	t_vec3		*center;
	double		diameter;
	t_colors	*colors;
}	t_sphere;
	
typedef	struct s_cene
{
	t_camera	*camera;
	t_list		*spheres;
}

#endif
