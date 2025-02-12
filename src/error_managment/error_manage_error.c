/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:25:45 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/12 15:55:56 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "error_managment.h"

void	error_manage_error(t_error *error)
{
	ft_putstr_fd(error->msg, 2);
	if (error->is_msg_freeable)
		free(error->msg);
	exit(error->exit_status);
}
