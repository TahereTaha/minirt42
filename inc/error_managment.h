/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mangment.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:06:05 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/12 15:25:13 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MANAGMENT_H
# define ERROR_MANAGMENT_H

//	errno is not only a copy of errno but it dose store custom errors 
typedef struct s_error
{
	int		errnum;
	int		exit_status;
	char	*msg;
	int		is_msg_freeable;
}	t_error;

void	error_clear(t_error *error);

void	error_change_msg(t_error *error, char *new_msg, int freeable);

void	error_get_sys_error(t_error *error);

int		error_is_sys_error(t_error *error);

void	error_apend_to_error_msg(t_error *error, char *str, int freeable);

void	error_manage_error(t_error *error);

#endif
