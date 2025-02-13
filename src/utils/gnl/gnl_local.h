/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_local.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:03:51 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/11 14:56:19 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_LOCAL_H
# define GNL_LOCAL_H

# include <aio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 70
# endif
# if BUFFER_SIZE < 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

char	*gnl_strcpy(char *dest, char *src, size_t len);
char	*gnl_strchr(char *str, char c);
size_t	gnl_strlen(char *str);
char	*gnl_strdup(char *str);
char	*gnl_substr(char *str, size_t statrt, size_t len);

#endif
