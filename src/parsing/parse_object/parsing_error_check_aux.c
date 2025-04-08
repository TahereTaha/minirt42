/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error_check_aux.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:59:30 by tatahere          #+#    #+#             */
/*   Updated: 2025/04/08 11:16:32 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "numbers.h"
#include "scene.h"
#include "parsing.h"
#include "error_managment.h"
#include "custom_errors.h"
#include "minirt.h"

int	count_chars(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	format_error_aux(char **coordinates, char *token)
{
	int	i;

	i = 0;
	if (!coordinates || ft_arraylen(coordinates) != 2)
		return (1);
	if (count_chars(token, ',') != 1)
		return (1);
	while (coordinates[i])
	{
		if (!ft_isfloat(coordinates[i]) || ft_isfloatoverflow(coordinates[i]))
			return (1);
		i++;
	}
	return (0);
}

int	format_error(char **coordinates, char *token)
{
	int	i;

	i = 0;
	if (!coordinates || ft_arraylen(coordinates) != 3)
		return (1);
	if (count_chars(token, ',') != 2)
		return (1);
	while (coordinates[i])
	{
		if (!ft_isfloat(coordinates[i]) || ft_isfloatoverflow(coordinates[i]))
			return (1);
		i++;
	}
	return (0);
}
