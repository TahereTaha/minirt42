/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:50:57 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/11 14:56:47 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "gnl.h"
#include "gnl_local.h"

char	*gnl_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*str;

	s1_len = gnl_strlen(s1);
	s2_len = gnl_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (0);
	gnl_strcpy(str, s1, s1_len);
	gnl_strcpy(str + s1_len, s2, s2_len);
	str[s1_len + s2_len] = '\0';
	return (str);
}

char	*read_line(int fd, char *str)
{
	char	*temp_str;
	ssize_t	n_bytes;
	char	*buf;

	buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (free(str), NULL);
	n_bytes = BUFFER_SIZE;
	while (!gnl_strchr(str, '\n') && n_bytes == BUFFER_SIZE && buf)
	{
		n_bytes = read(fd, buf, BUFFER_SIZE);
		if (n_bytes < 0 || (!n_bytes && !gnl_strlen(str)))
			return (free(str), free(buf), NULL);
		buf[n_bytes] = '\0';
		temp_str = gnl_strjoin(str, buf);
		free(str);
		if (!temp_str)
			return (free(buf), (char *)0);
		str = temp_str;
	}
	return (free(buf), str);
}

char	*get_next_line(int fd)
{
	static char		*str[OPEN_MAX];
	char			*temp_str;
	char			*next_str;
	char			*nl_str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (!str[fd] || !(str[fd][0]) || !gnl_strchr(str[fd], '\n'))
		str[fd] = read_line(fd, str[fd]);
	temp_str = str[fd];
	if (!gnl_strchr(str[fd], '\n'))
		return (str[fd] = NULL, temp_str);
	next_str = gnl_strchr(str[fd], '\n') + 1;
	nl_str = gnl_substr(str[fd], 0, next_str - str[fd]);
	str[fd] = gnl_strdup(next_str);
	free(temp_str);
	if (!str[fd] || !nl_str)
		return (free(str[fd]), free(nl_str), str[fd] = 0, NULL);
	return (nl_str);
}
