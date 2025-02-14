/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_errors.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:06:05 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/14 19:27:13 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_ERRORS_H
# define CUSTOM_ERRORS_H

//
//	this file will have all the custom errors that the program can have.
//	and it includes some function related to dose.
//

# define LAST_SYS_ERROR 132
# define FIRST_CUSTOM_ERROR 140

//	some custom error that this project can have.
typedef enum e_error_kind
{
	NOT_A_NUMBER = FIRST_CUSTOM_ERROR,
	WRONG_ARGUMENT_COUNT,
	WRONG_FILE_TERMINATION,
	DUPLICATED_OBJECT
}	t_error_kind;

const static char	*error_msg[] = {\
	"unable to interpret data it is not a number.",	\
	"number of arguments is incorect. \
	please provide one argument being the file.",	\
	"the file has the wrong termination. \
	please provide a .rt file.", 					\
	"you can't declane more than onec this object."	\
};

char	*ft_strerror(int errnum);

#endif
