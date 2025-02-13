/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:28:41 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/13 13:56:46 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "ft_list.h"
# include "vector_math.h"
# include "error_managment.h"

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_ambient_light
{
	t_color	light_color;
	double	light_ratio;
}	t_ambient_light;

typedef struct s_camera
{
	t_vec3	view_point;
	t_vec3	orientation;
	double	fov_rad;
}	t_camera;

typedef struct s_light
{
	t_vec3	position;
	t_color	ligth_color;
	double	ligth_ratio;
}	t_light;

typedef enum e_object_kind
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_object_kind;

//	this is just a structure that holds the object it it.
typedef struct s_object
{
	t_object_kind	kind;
	void			*content;
}	t_object;

typedef struct s_sphere
{
	t_vec3	position;
	t_color	color;
	double	diameter;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	position;
	t_color	color;
	t_vec3	orientation;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	position;
	t_vec3	orientation;
	t_color	color;
	double	diameter;
	double	height;
}	t_cylinder;

typedef	struct s_cene
{
	t_ambient_ligth	ambient_ligth;
	t_camera		camera;
	t_ligth			ligth;
	t_list			*object;
	int				is_abient_ligth_set;
	int				is_camera_set;
	int				is_ligth_set;
}	t_scene;

t_cene	*cene_create(void);
void	cene_clear(t_cene *cene);
void	cene_delete(t_cene *cene);

#endif
