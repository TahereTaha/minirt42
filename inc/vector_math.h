/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 07:08:15 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/21 12:47:54 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_MATH_H
# define VECTOR_MATH_H

//	a vetror in the 2d space.
typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

//	a vetror in the 3d space.
typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

//	a 3x3 matrix


//	debug prints.
void	vec2_print(t_vec2 vector);
void	vec2_print_multiline(t_vec2 vector);
void	vec3_print(t_vec3 vector);
void	vec3_print_multiline(t_vec3 vector);

//	vector propertis.
int		vec2_is_null(t_vec2 vector);
int		vec3_is_null(t_vec3 vector);

//	magnitudes.
double	vec2_get_magnitude(t_vec2 vector);
double	vec3_get_magnitude(t_vec3 vector);

//	vector addition.
t_vec2	vec2_add(t_vec2 vector1, t_vec2 vector2);
t_vec3	vec3_add(t_vec3 vector1, t_vec3 vector2);

//	vector substraction.
t_vec2	vec2_sub(t_vec2 vector1, t_vec2 vector2);
t_vec3	vec3_sub(t_vec3 vector1, t_vec3 vector2);

//	vector scaling.
t_vec2	vec2_scale(t_vec2 vector, double scalar);
t_vec3	vec3_scale(t_vec3 vector, double scalar);

//	vector normalization.
t_vec2	vec2_normalize(t_vec2 vector);
t_vec3	vec3_normalize(t_vec3 vector);

// vector cross product
t_vec3 vec2_cross_product(t_vec3 a, t_vec3 b);
double vec3_cross_product_2d(t_vec2 a, t_vec2 b);

//	linear combination.
t_vec2	vec2_linear_combination(	t_vec2 vector1, double scalar1, \
									t_vec2 vector2, double scalar2);
t_vec3	vec3_linear_combination(	t_vec3 vector1, double scalar1, \
									t_vec3 vector2, double scalar2);

//	matrix multiplication.
t_matrix3	matrix3_multiply(t_matrix3 a, t_matrix3 b);


//
//
//
/*
//	angles.
double	vec2_get_angle(t_vec2 vector);			//	the only usfull one.
double	vec3_get_angle_x_axis(t_vec3 vector);	//	redo
double	vec3_get_angle_y_axis(t_vec3 vector);	//	redo
double	vec3_get_angle_z_axis(t_vec3 vector);	//	redo

//	vector creator.
t_vec2	vec2_create(double magnitude, double angle_rad);	
t_vec3	vec3_create(double magnitude, double angle_z_rad, double angle_y_rad);	//	redo
*/

#endif
