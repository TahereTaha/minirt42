/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_is_sys_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:42:18 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/12 12:44:59 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "error_managment.h"

int		error_is_sys_error(t_error *error)
{
	if (error->errnum < 132 && error->errnum != 0)
		return (1);
	return (0);
}
