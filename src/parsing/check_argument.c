/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:00:44 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/14 19:13:58 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_error.h"
#include "error_managment.h"

static int	file_correct_termination(char *file)
{
	if (ft_strncmp(".rt", &(file[ft_strlen(av[1]) - 3]), 4))
		return (0);
	return (1);
}

void	check_argument(t_error *error, int ac, char **av)
{
	if (ac != 2)
	{
		error_set(error, WRONG_ARGUMENT_COUNT);
		return ;
	}
	if (file_corret_termination(av[i]))
	{
		error_set(error, WRONG_FILE_TERMINATION);
		return ;
	}
}
