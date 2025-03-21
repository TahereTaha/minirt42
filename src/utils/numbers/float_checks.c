/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:57:40 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/21 11:19:57 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "numbers.h"

static int	check_decimal_part(char *str)
{
	int	decimal_count;
	int	i;

	decimal_count = 0;
	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (!str[i])
		return (0);
	i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		decimal_count++;
		i++;
	}
	return (decimal_count > 6);
}

int	ft_isfloatoverflow(char *str)
{
	long double	num;
	char		*dot_pos;
	int			int_len;

	if (!str || !*str)
		return (true);
	dot_pos = ft_strchr(str, '.');
	if (dot_pos)
		int_len = dot_pos - str;
	else
		int_len = ft_strlen(str);
	if (str[0] == '-' || str[0] == '+')
		int_len--;
	if (int_len > 38)
		return (true);
	if (check_decimal_part(str))
		return (true);
	num = ft_atof(str);
	if (num > FLTMAX || num < MFLTMAX)
		return (true);
	return (false);
}

int	ft_isfloat(char *str)
{
	int	i;
	int	has_dot;
	int	has_digit;

	if (!str || !*str)
		return (false);
	i = 0;
	has_dot = 0;
	has_digit = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			has_digit = 1;
		else if (str[i] == '.')
		{
			if (has_dot)
				return (false);
			has_dot = 1;
		}
		else
			return (false);
		i++;
	}
	return (has_digit);
}
