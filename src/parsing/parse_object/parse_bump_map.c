/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bump_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:43:59 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/08 09:59:31 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <errno.h>
#include "MLX42/MLX42.h"
#include "libft.h"
#include "numbers.h"
#include "scene.h"
#include "parsing.h"
#include "error_managment.h"
#include "custom_errors.h"

static int	is_on_off(t_error *error, char *str)
{
	if (!ft_strncmp(str, "on", -1))
		return (1);
	if (!ft_strncmp(str, "off", -1))
		return (0);
	error_set(error, INVALID_FORMAT);
	return (0);
}

static char	**local_split(t_error *error, char *str)
{
	char	**tokens;

	tokens = ft_split(str, ':');
	if (!tokens)
	{
		error_set(error, errno);
		return (NULL);
	}
	if (ft_arraylen(tokens) != 4)
	{
		free_array(tokens);
		error_set(error, WRONG_TOKENS_COUNT);
		return (NULL);
	}
	return (tokens);
}

void	set_bump_map_w_h(t_error *error, t_bump_map *bump_map, char *str)
{
	char	**tokens;

	tokens = ft_split(str, ',');
	if (!tokens)
	{
		error_set(error, errno);
		return ;
	}
	if (ft_arraylen(tokens) != 2)
	{
		error_set(error, WRONG_TOKENS_COUNT);
		return ;
	}
	if (format_error_aux(tokens))
	{
		error_set(error, WRONG_TOKENS_COUNT);
		return ;
	}
	bump_map->width = ft_atof(tokens[0]);
	bump_map->height = ft_atof(tokens[1]);
}

void	parse_bump_map_file(t_error *error, t_bump_map *bump_map, char *file)
{
	if (error->errnum)
		return ;
	bump_map->texture = mlx_load_png(file);
	if (!bump_map)
		error_set(error, mlx_errno);
}

t_bump_map	get_bump_map(t_error *error, char *token)
{
	char		**tokens;
	t_bump_map	bump_map;

	tokens = local_split(error, token);
	if (error->errnum)
		return (bump_map);
	if (ft_strncmp(tokens[0], "bump_map", -1))
	{
		free_array(tokens);
		error_set(error, INVALID_FORMAT);
		return (bump_map);
	}
	bump_map.on = is_on_off(error, tokens[1]);
	if (error->errnum)
	{
		free_array(tokens);
		return (bump_map);
	}
	set_bump_map_w_h(error, &bump_map, tokens[2]);
	parse_bump_map_file(error, &bump_map, tokens[3]);
	free_array(tokens);
	return (bump_map);
}
