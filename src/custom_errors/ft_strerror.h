/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerror.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:56:34 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/21 07:34:26 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRERROR_H
# define FT_STRERROR_H

static const char	*g_error_msg[] = {\
	"unable to interpret data it is not a number.",		\
	"number of arguments is incorect.\
	please provide one argument being the file.",		\
	"the file has the wrong termination.\
	please provide a .rt file.",						\
	"you can't declane more than onec this object.",	\
	"the object idenifier dosen't mach any.\
   	maybe it is mispelled, try to check again.",		\
	"wrong amount of tokens.",							\
	"invalid format: check input format requirements",	\
	"invalid range: value is outside allowed range"		\
};

#endif
