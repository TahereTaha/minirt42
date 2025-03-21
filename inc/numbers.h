/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:17:03 by tatahere          #+#    #+#             */
/*   Updated: 2025/03/21 11:17:05 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBERS_H
# define NUMBERS_H

# include <stdbool.h>

/* Float number checking and conversion functions */
int		ft_isfloat(char *str);
int		ft_isfloatoverflow(char *str);
float	ft_atof(char *str);

/* Integer checking functions */
int		ft_isint(char *str);
int		is_intoverflow(char *str);

# define PI 3.14159265359

double	deg_to_rad(double deg);

#endif
