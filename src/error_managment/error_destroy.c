/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:17:02 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/14 16:19:27 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "error_managment.h"
#include "error_managment_local.h"

void	error_destroy(t_error *error)
{
	if (!error)
		return ;
	error_msg_destroy(error);
	free(error);
}
