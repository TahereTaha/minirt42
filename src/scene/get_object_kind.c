/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object_kind.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:18:58 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/21 10:37:16 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene.h"
#include "get_object_kind.h"

t_object_kind	get_object_kind(char *str)
{
	int		i;
	char	*id_str;

	i = 0;
	if (str[0] == ' ' || str[0] == '\0')
		return (BLANK);
	while (i < OBJECT_AMOUNT)
	{
		id_str = (char *)g_object_str_identifier[i];
		if (!ft_strncmp(id_str, str, ft_strlen(id_str)))
			return (i + 1);
		i++;
	}
	return (UNEXISTENT);
}
