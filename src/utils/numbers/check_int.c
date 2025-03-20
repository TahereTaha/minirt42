/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:57:18 by rgiambon          #+#    #+#             */
/*   Updated: 2025/03/20 14:18:04 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numbers.h"
#include "libft.h"
#include <ctype.h>
#include <limits.h>

int	ft_isint(char *str)
{
	int	i;

	i = 0;
	while (isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!isdigit(str[i]))
		return (0);
	while (isdigit(str[i]))
		i++;
	return (str[i] == '\0');
}

int	is_intoverflow(char *str)
{
	int	i;
	int	result;
	int	digit;

	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (ft_isdigit(str[i]))
	{
		digit = str[i] - '0';
		if (result > (INT_MAX - digit) / 10)
			return (1);
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (0);
}
