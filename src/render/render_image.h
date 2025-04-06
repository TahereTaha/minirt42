/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:28:58 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/06 20:42:46 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_IMAGE_H
# define RENDER_IMAGE_H

# include "minirt.h"
# include "scene.h"
# include "MLX42/MLX42.h"

# define THREAD_COUNT 16.0

# define LINE_HEIGHT WIN_HEIGHT / THREAD_COUNT

typedef struct s_render_child
{
	mlx_image_t	*img;
	t_scene		*sc;
	int			index;
}	t_render_child;

typedef void *(*t_void_ptr_fn)(void *);

#endif
