/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:08:54 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/16 17:03:40 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "ft_list.h"
# include "vector_math.h"
# include "error_managment.h"

//	some usefull structs.
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

//	objects.

typedef enum e_object_kind
{
	BLANK,
	AMBIENT_LIGHT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	UNEXISTENT
}	t_object_kind;

typedef struct s_object
{
	t_object_kind	kind;
}	t_object;

typedef struct s_ambient_light
{
	t_object	object;
	t_color		light_color;
	double		light_ratio;
}	t_ambient_light;

typedef struct s_camera
{
	t_object	object;
	t_vec3		view_point;
	t_vec3		orientation;
	double		fov_rad;
}	t_camera;

typedef struct s_light
{
	t_object	object;
	t_vec3		position;
	t_color		ligth_color;
	double		ligth_ratio;
}	t_light;

typedef struct s_sphere
{
	t_object	object;
	t_vec3		position;
	t_color		color;
	double		diameter;
}	t_sphere;

typedef struct s_plane
{
	t_object	object;
	t_vec3		position;
	t_color		color;
	t_vec3		orientation;
}	t_plane;

typedef struct s_cylinder
{
	t_object	object;
	t_vec3		position;
	t_vec3		orientation;
	t_color		color;
	double		diameter;
	double		height;
}	t_cylinder;

typedef	struct s_scene
{
	t_ambient_light	ambient_light;
	t_camera		camera;
	t_light			light;
	t_list			*objects;
}	t_scene;

t_scene	*scene_create(void);
void	scene_destroy(t_scene *cene);

# define OBJECT_AMOUNT 6

const static char	*object_str_identifier[] = {\
	"A",	\
	"C",	\
	"L",	\
	"sp",	\
	"pl",	\
	"cy"	\
};

t_object_kind	get_object_kind(char *str);

#endif
