/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_disrupt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:43:59 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/08 10:21:47 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
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
	if (ft_arraylen(tokens) != 3)
	{
		free_array(tokens);
		error_set(error, WRONG_TOKENS_COUNT);
		return (NULL);
	}
	return (tokens);
}

void	set_disrupt_w_h(t_error *error, t_disrupt *disrupt, char *str)
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
	if (format_error_aux(tokens, str))
	{
		error_set(error, WRONG_TOKENS_COUNT);
		return ;
	}
	disrupt->height = ft_atof(tokens[0]);
	disrupt->width = ft_atof(tokens[1]);
}

t_disrupt	get_disruption(t_error *error, char *token)
{
	char		**tokens;
	t_disrupt	disrupt;

	tokens = local_split(error, token);
	if (error->errnum)
		return (disrupt);
	if (ft_strncmp(tokens[0], "color_disruption", -1))
	{
		free_array(tokens);
		error_set(error, INVALID_FORMAT);
		return (disrupt);
	}
	disrupt.on = is_on_off(error, tokens[1]);
	if (error->errnum)
		return (disrupt);
	set_disrupt_w_h(error, &disrupt, tokens[2]);
	return (disrupt);
}
