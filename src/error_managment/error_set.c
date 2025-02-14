/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:19:23 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/14 16:31:52 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include "custom_errors.h"
#include "error_managment.h"
#include "error_managment_local.h"

void	error_set(t_error *error, int errnum)
{
	if (!errnum)
		return ;
	error->errnum = errnum;
	error->exit_status = 1;
	error_msg_set(error, ft_strerror(errnum), 0);
}
