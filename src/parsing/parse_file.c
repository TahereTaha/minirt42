/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:48:58 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/21 10:52:50 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "custom_errors.h"
#include "error_managment.h"
#include "parsing.h"
#include "scene.h"
#include "gnl.h"

void	read_file(t_error *error, t_scene *scene, int fd)
{
	char			*line;
	int				line_num;

	line_num = 0;
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (errno)
		{
			error_set(error, errno);
			return ;
		}
		if (!line)
			return ;
		parse_line(error, scene, line);
		free(line);
		if (error->errnum)
		{
			error_msg_append_line(error, line_num + 1);
			return ;
		}
		line_num++;
	}
}

void	parse_file(t_error *error, t_scene *scene, int ac, char **av)
{
	int	fd;

	check_argument(error, ac, av);
	if (error->errnum)
		return ;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_set(error, errno);
	if (!error->errnum)
		read_file(error, scene, fd);
	if (error->errnum)
		error_msg_append(error, "parsin: ", 0);
}
