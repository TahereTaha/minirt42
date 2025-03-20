/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:00:52 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/20 12:45:15 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "renderer.h"

//	this will combine two colors.
t_color	add_color(t_color color1, t_color color2)
{
	t_color new_color;

	new_color.r = color1.r + color2.r;
	if (new_color.r > 255 && new_color.r < 0)
		new_color.r = 255;
	new_color.g = color1.g + color2.g;
	if (new_color.g > 255 && new_color.g < 0)
		new_color.g = 255;
	new_color.b = color1.b + color2.b;
	if (new_color.b > 255 && new_color.b < 0)
		new_color.b = 255;
	return (new_color);
}

//	this will return the color seen by iluminating it with a light.
t_color light_color(t_color color, t_color light)
{
	t_color	new_color;
	double	scalar;

	scalar = ((double) light.r) / 255.0;
	new_color.r = color.r * scalar;
	scalar = ((double) light.g) / 255.0;
	new_color.g = color.g * scalar;
	scalar = ((double) light.b) / 255.0;
	new_color.b = color.b * scalar;
	return (new_color);
}

t_color	scale_color(t_color color, double scalar)
{
	t_color new_color;

	new_color.r = color.r * scalar;
	if (new_color.r > 255)
		new_color.r = 255;
	new_color.g = color.g * scalar;
	if (new_color.g > 255)
		new_color.g = 255;
	new_color.b = color.b * scalar;
	if (new_color.b > 255)
		new_color.b = 255;
	return (new_color);
}
