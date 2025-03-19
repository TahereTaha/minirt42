/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambient_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 05:40:06 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/19 05:40:41 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "scene.h"
#include "renderer.h"
#include "ft_list.h"

t_color	get_ambient_light(t_ambient_light ambient_light)
{
	t_color	light;

	light = ambient_light.light_color;
	light = scale_color(light, ambient_light.light_ratio);
	return (light);
}
