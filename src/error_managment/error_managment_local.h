/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_managment_local.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:06:05 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/14 16:20:54 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MANAGMENT_LOCAL_H
# define ERROR_MANAGMENT_LOCAL_H

#include "error_managment.h"

void	error_msg_destroy(t_error *error);

void	error_msg_set(t_error *error, char *new_msg, int freeable);

#endif
