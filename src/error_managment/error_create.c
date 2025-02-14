/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:00:46 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/14 16:07:19 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "libft.h"
#include "error_managment.h"

t_error	*error_create(void)
{
	t_error	*new_error_ctx;

	new_error_ctx = ft_calloc(sizeof(t_error), 1);
	if (new_error_ctx)
		return (new_error_ctx);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	exit(1);
	return (NULL);
}
