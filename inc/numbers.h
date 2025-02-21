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

#endif
