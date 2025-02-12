/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_append_to_error_msg.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:44:18 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/12 15:23:45 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "libft.h"
#include "error_managment.h"

void	error_apend_to_error_msg(t_error *error, char *str, int freeable)
{
	char	*new_msg;

	if (!error->msg)
	{
		error->is_msg_freable = freable;
		error->msg = msg;
		return ;
	}
	new_msg = ft_strjoin(error->msg, str);
	if (!new_msg)
	{
		error_get_sys_error(error);
		return ;
	}
	error_change_msg(error, new_msg, 1);
}
