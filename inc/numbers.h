#ifndef NUMBERS_H
# define NUMBERS_H

# include <stdbool.h>

/* Float number checking and conversion functions */
bool	ft_isfloat(const char *str);
bool	ft_isfloatoverflow(const char *str);
float	ft_atof(char *str);

/* Integer checking functions */
int		ft_isint(const char *str);
bool	is_intoverflow(char *str);

#endif
