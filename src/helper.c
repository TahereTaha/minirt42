/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:37:47 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/06 11:58:18 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "stdlib.h"
#include "unistd.h"
#include "stdio.h"

int	main(int ac, char **av)
{
	int		number;

	(void)ac;
	number = strtol(av[1], NULL, 16);
	printf("%i,%i,%i\n",	number / (int)pow(16, 4), \
							(number >> 8) % (int)pow(16, 2), \
							number % (int)pow(16, 2) );
	return (0);
}
