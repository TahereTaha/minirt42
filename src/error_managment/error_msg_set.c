/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:11:57 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/14 16:23:05 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "error_managment.h"
#include "error_managment_local.h"

void	error_msg_set(t_error *error, char *new_msg, int freeable)
{
	error_msg_destroy(error);
	error->is_msg_freeable = freeable;
	error->msg = new_msg;
}
