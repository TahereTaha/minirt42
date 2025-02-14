/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_managment.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:06:05 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/14 16:45:11 by tatahere         ###   ########.fr       */
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

//	this will create a new error ctx.
t_error	*error_create(void);

//	this will free everithig holded by error.
void	error_destroy(t_error *error);

//	this will erase the error and set errno to 0.
void	error_clear(t_error *error);

//	this will set the error to whatever the errnum is and get the msg.
void	error_set(t_error *error, int errnum);

//	will return 1 if it is a system error or 0 if it is custom.
int		error_is_sys(t_error *error);

//	will apend to the left of the error msg the string provided.
void	error_msg_append(t_error *error, char *str, int freeable);

//	will print the msg and exit with the seted exit status.
void	error_manage(t_error *error);

#endif
