/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cene_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:10:47 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/13 11:13:34 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

t_cene	*cene_create(void)
{
	t_cene	*cene;

	cene = ft_calloc(sizeof(t_cene), 1);
	return (cene);
}
