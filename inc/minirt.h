/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:28:41 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/12 12:00:50 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

typedef struct s_camera
{
	t_coordinates origin;
	t_coordinates direction;
	t_coordinates fov;
}	t_camera;
	
typedef	struct s_cene
{
	t_camera	camera;
	t_list		*spheres;
}

#endif
