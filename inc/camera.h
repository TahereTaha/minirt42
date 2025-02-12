#ifndef CAMERA_H
#define CAMERA_H

typedef struct s_coordinates
{
	float	x;
	float	y;
	float	z;
}	t_coordinates;

typedef struct s_camera
{
	t_coordinates origin;
	t_coordinates direction;
	t_coordinates fov;
	
}	t_camera;

#endif
