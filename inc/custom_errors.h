/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_errors.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:06:05 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/20 16:28:01 by tatahere         ###   ########.fr       */
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

//	the error can have any order but
//	it must be the same as the error_msg and
//	the first sould be allways ecual to the FIRST_CUSTOM_ERROR.
typedef enum e_error_kind
{
	NOT_A_NUMBER = FIRST_CUSTOM_ERROR,
	WRONG_ARGUMENT_COUNT,
	WRONG_FILE_TERMINATION,
	DUPLICATED_OBJECT,
	WRONG_OBJECT_IDENTIFIER,
	WRONG_TOKENS_COUNT,
	INVALID_FORMAT,
	INVALID_RANGE,
}	t_error_kind;


char	*ft_strerror(int errnum);

#endif
