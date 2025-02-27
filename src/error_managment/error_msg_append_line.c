/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg_append_line.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:05:26 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/19 12:14:33 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include "libft.h"
#include "error_managment.h"

void	error_msg_append_line(t_error *error, int line_num)
{
	char	*line_num_str;
	char	*new_msg;

	line_num_str = ft_itoa(line_num);
	if (!line_num_str)
	{
		error_set(error, errno);
		return ;
	}
	new_msg = ft_strjoin(":", error->msg);
	if (!new_msg)
	{
		error_set(error, errno);
		return ;
	}
	error_msg_set(error, new_msg, 1);
	new_msg = ft_strjoin(line_num_str, error->msg);
	free(line_num_str);
	if (!new_msg)
	{
		error_set(error, errno);
		return ;
	}
	error_msg_set(error, new_msg, 1);
}
