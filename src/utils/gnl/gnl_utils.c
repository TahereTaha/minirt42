/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 07:40:20 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/11 14:57:07 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "gnl_local.h"

char	*gnl_strcpy(char *dest, char *src, size_t len)
{
	size_t	i;

	if (!src)
		return (dest);
	i = 0;
	while (src[i] && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*gnl_strchr(char *str, char c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (&str[i]);
	return (0);
}

size_t	gnl_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strdup(char *str)
{
	size_t	len;
	char	*dup;

	len = gnl_strlen(str);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (0);
	gnl_strcpy(dup, str, len + 1);
	return (dup);
}

char	*gnl_substr(char *str, size_t start, size_t len)
{
	char	*substr;

	if (start > gnl_strlen(str))
		return (gnl_strdup(""));
	if ((gnl_strlen(str) - start) < len)
		len = (gnl_strlen(str) - start);
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (0);
	gnl_strcpy(substr, str, len);
	return (substr);
}
