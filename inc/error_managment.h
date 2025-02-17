/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_managment.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:06:05 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/17 15:15:19 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MANAGMENT_H
# define ERROR_MANAGMENT_H

//	if you try to change any of the values of the structure it may lead to undefined ve

//	errno is not only a copy of errno but it dose store custom errors 
typedef struct s_error
{
	int		errnum;
	int		exit_status;
	char	*msg;
	int		is_msg_freeable;
}	t_error;

t_error	*error_create(void);
void	error_destroy(t_error *error);
void	error_clear(t_error *error);
void	error_set(t_error *error, int errnum);
int		error_is_sys(t_error *error);
void	error_msg_set(t_error *error, char *new_msg, int freeable);
void	error_msg_append(t_error *error, char *str, int freeable);
void	error_msg_append_line(t_error *error, int line_num);
void	error_manage(t_error *error);

#endif
