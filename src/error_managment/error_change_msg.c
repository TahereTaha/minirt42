/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_change_msg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:11:57 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/12 15:15:08 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_managment.h"

void	error_change_msg(t_error *error, char *new_msg, int freeable)
{
	if (error->is_msg_freable)
		free(error->msg);
	error->is_msg_freable = freeable;
	error->msg = new_msg;
}
