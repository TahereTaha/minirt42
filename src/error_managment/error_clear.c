/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:17:14 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/12 15:38:26 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_managment.h"

void	error_clear(t_error *error)
{
	error->errnum = 0;
	error->exit_status = 0;
	error->msg = "no error exiting successful\n";
	error->is_msg_freeable = 0;
}
