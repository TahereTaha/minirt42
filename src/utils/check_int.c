/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:57:18 by rgiambon          #+#    #+#             */
/*   Updated: 2025/02/13 11:57:50 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../libs/libft.h"

int ft_isint(const char *str)
{
	int	i;

	i = 0;
	while (isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!isdigit(str[i]))
		return 0;
	while (isdigit(str[i]))
		i++;
	return (str[i] == '\0');
}

bool	is_intoverflow(char *str)
{
	int	i;
	int	result;
	int	sign;
	int digit;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
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
