/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:59:59 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/20 16:31:38 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "custom_errors.h"
#include "ft_strerror.h"

char	*ft_strerror(int errnum)
{
	if (errnum < FIRST_CUSTOM_ERROR)
		return (strerror(errnum));
	return ((char *)g_error_msg[errnum - FIRST_CUSTOM_ERROR]);
}
