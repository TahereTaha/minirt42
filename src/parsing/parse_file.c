/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:48:58 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/14 19:25:50 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <errno.h>
#include "custom_errors.h"
#include "error_managment.h"
#include "parsing.h"

void	read_file(int fd)
{
	char			*line;
	t_object_kind	kind;

	line = get_next_line(fd);
	while (line)
	{

		line = get_next_line(fd);
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
	{
		error_set(error, errno);
		error_msg_append(error, "parsin: ", 0);
		return ;
	}
	
}
