/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:27:57 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/21 11:16:33 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "numbers.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void	ft_process_int(char *str, int *i, float *result)
{
	while (ft_isdigit(str[*i]))
	{
		*result = *result * 10.0f + (str[*i] - '0');
		(*i)++;
	}
}

void	ft_process_frac(char *str, int *i, float *result, float *divisor)
{
	if (str[*i] == '.')
	{
		(*i)++;
		while (ft_isdigit(str[*i]))
		{
			*result = *result * 10.0f + (str[*i] - '0');
			*divisor *= 10.0f;
			(*i)++;
		}
	}
}

float	ft_atof(char *str)
{
	int		i;
	float	result;
	int		sign;
	float	divisor;

	i = 0;
	sign = 1;
	result = 0.0f;
	divisor = 1.0f;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	ft_process_int(str, &i, &result);
	ft_process_frac(str, &i, &result, &divisor);
	result = (result * sign) / divisor;
	return (result);
}
