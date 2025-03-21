/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:59:59 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/21 07:33:24 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "custom_errors.h"
#include "MLX42/MLX42.h"
#include "ft_strerror.h"

char	*ft_strerror(int errnum)
{
	if (errnum < FIRST_MLX_ERROR)
		return (strerror(errnum));
	if (errnum < FIRST_CUSTOM_ERROR)
		return ((char *)mlx_strerror(errnum));
	return ((char *)g_error_msg[errnum - FIRST_CUSTOM_ERROR]);
}
