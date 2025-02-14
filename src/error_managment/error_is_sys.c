/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_is_sys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:42:18 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/14 16:36:40 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "error_managment.h"
#include "custom_errors.h"

int		error_is_sys(t_error *error)
{
	if (error->errnum < LAST_SYS_ERROR && error->errnum != 0)
		return (1);
	return (0);
}
