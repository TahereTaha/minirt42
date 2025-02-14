/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:37:20 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/14 16:51:00 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include "libft.h"
#include "vector_math.h"
#include "error_managment.h"
#include "custom_errors.h"

int	main(void)
{
	t_error	*error;

	error = error_create();
	error_clear(error);
	error_destroy(error);
	return (0);
}
