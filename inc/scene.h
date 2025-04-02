/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:08:54 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/02 11:41:09 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "ft_list.h"
# include "vector_math.h"
# include "error_managment.h"
# include "MLX42/MLX42.h"

//	some usefull structs.
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}		t_color;

//	objects.

# define OBJECT_AMOUNT 8

typedef enum e_object_kind
{
	BLANK,
	AMBIENT_LIGHT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
	COMMENT,
	UNEXISTENT
}	t_object_kind;

//	All objects that means:
//		the camera, ambient lighting, sphere, cilinder and all the other.
//	Will have at the start the t_object_kind.
//	So that they can be treated like any other object 
//	
//	in a way they all are desendent of a
//	object class that has only the kind of object.

typedef struct s_ambient_light
{
	t_object_kind	kind;
	t_color			light_color;
	double			light_ratio;
}	t_ambient_light;

//	please use thin in the most dier of circustances only.
typedef t_ambient_light	t_al;

typedef struct s_camera
{
	t_object_kind	kind;
	t_vec3			view_point;
	t_vec3			orientation;
	double			fov_rad;
}	t_camera;

typedef struct s_light
{
	t_object_kind	kind;
	t_vec3			position;
	t_color			light_color;
	double			light_ratio;
}	t_light;

typedef struct s_sphere
{
	t_object_kind	kind;
	t_vec3			position;
	t_color			color;
	double			diameter;
}	t_sphere;

typedef	struct s_color_disrpt
{
	int		on;
	float	with;
	float	height;
}	t_disrupt;

typedef	struct s_bump_map
{
	int				on;
	float			with;
	float			height;
	mlx_texture_t	*texture;
}	t_bump_map;

typedef struct s_plane
{
	t_object_kind	kind;
	t_vec3			position;
	t_color			color;
	t_vec3			orientation;
	t_disrupt		color_disruption;
	t_bump_map		bump_map;
}	t_plane;

typedef struct s_cylinder
{
	t_object_kind	kind;
	t_vec3			position;
	t_vec3			orientation;
	t_color			color;
	double			diameter;
	double			height;
}	t_cylinder;

typedef struct s_cone
{
	t_object_kind	kind;
	t_vec3			position;
	t_vec3			orientation;
	t_color			color;
	double			diameter;
	double			height;
}	t_cone;

typedef union u_bigest_object
{
	t_ambient_light	object1;
	t_camera		object2;
	t_light			object3;
	t_sphere		object4;
	t_plane			object5;
	t_cylinder		object6;
	t_cone			object7;
}	t_bigest_object;

typedef struct s_object
{
	t_object_kind	kind;
	char			pading[sizeof (t_bigest_object) - sizeof (t_object_kind)];
}		t_object;

t_object_kind	get_object_kind(char *str);
t_object		object_create(t_error *error, char *line);

typedef struct s_scene
{
	t_ambient_light	ambient_light;
	t_camera		camera;
	t_list			*lights;
	t_list			*objects;
}					t_scene;

t_scene			*scene_create(void);
void			scene_destroy(t_scene *cene);

void			scene_object_add(t_error *error, t_scene *scene, t_object obj);
void			scene_light_list_add(t_error *err, t_scene *scn, t_object obj);
void			scene_object_list_add(t_error *err, t_scene *s, t_object obj);

#endif
