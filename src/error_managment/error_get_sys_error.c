/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_get_sys_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:13:45 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/12 15:53:26 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include "error_managment.h"

void	error_get_sys_error(t_error *error)
{
	if (!errno)
		return ;
	error->errnum = errno;
	error->exit_status = 1;
	error_change_msg(error, strerror(errno), 0);
}
