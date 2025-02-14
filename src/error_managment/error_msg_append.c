/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:44:18 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/14 16:47:44 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "libft.h"
#include "error_managment.h"
#include "error_managment_local.h"

void	error_msg_append(t_error *error, char *str, int freeable)
{
	char	*new_msg;

	if (!error->msg)
	{
		error->is_msg_freeable = freeable;
		error->msg = str;
		return ;
	}
	new_msg = ft_strjoin(str, error->msg);
	if (!new_msg)
	{
		error_set(error, errno);
		return ;
	}
	if (freeable)
		free(str);
	error_msg_set(error, new_msg, 1);
}
