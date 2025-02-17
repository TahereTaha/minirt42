#include "libft.h"
#include <float.h>

static int	check_decimal_part(const char *str)
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

bool	is_floatoverflow(const char *str)
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
	if (num > FLT_MAX || num < -FLT_MAX)
		return (true);
	return (false);
}
