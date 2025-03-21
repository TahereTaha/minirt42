/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:18:57 by rgiambon          #+#    #+#             */
/*   Updated: 2025/03/21 11:23:08 by tatahere         ###   ########.fr       */
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
# define FLTMAX 3.402823466e+38  
# define MFLTMAX -3.402823466e+38

double	deg_to_rad(double deg);

#endif
