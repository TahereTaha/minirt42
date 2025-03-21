/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder_aux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:00:14 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/21 09:00:51 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libft.h"
#include "numbers.h"
#include "scene.h"
#include "parsing.h"
#include "error_managment.h"
#include "custom_errors.h"

void	parse_color_cylinder(t_error *error, char *token, t_cylinder *cylinder)
{
	char	**color;

	color = ft_split(token, ',');
	if (!color)
	{
		error_set(error, errno);
		return ;
	}
	if (format_error(color))
	{
		error_set(error, INVALID_FORMAT);
		free_array(color);
		return ;
	}
	cylinder->color.r = ft_atoi(color[0]);
	cylinder->color.g = ft_atoi(color[1]);
	cylinder->color.b = ft_atoi(color[2]);
	if (color_error(&cylinder->color))
	{
		error_set(error, INVALID_RANGE);
		free_array(color);
		return ;
	}
	free_array(color);
}
