/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object_kind.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:18:58 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/16 16:57:17 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene.h"

t_object_kind	get_object_kind(char *str)
{
	int		i;
	char	*id_str;

	i = 0;
	if (str[0] == ' ' || str[0] == '\n')
		return (BLANK);
	while (i < 6)
	{
		id_str = (char *)object_str_identifier[i];
		if (!ft_strncmp(id_str, str, ft_strlen(id_str)))
			return (i + 1);
		i++;
	}
	return (UNEXISTENT);
}
