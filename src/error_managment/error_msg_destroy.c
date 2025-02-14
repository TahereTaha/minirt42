/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:11:26 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/14 16:18:48 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "error_managment.h"
#include "error_managment_local.h"

void	error_msg_destroy(t_error *error)
{
	if (error->is_msg_freeable)
	{
		free(error->msg);
		error->is_msg_freeable = 0;
	}
	error->msg = NULL;
}
