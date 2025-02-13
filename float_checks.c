bool	is_floatoverflow(char *str)
{

}

bool ft_isfloat(const char *str)
{
	int	i;
	int	has_dot;
	int	has_digit;

	i = 0;
	has_dot = 0;
	has_digit = 0;
	while (isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (isdigit(str[i]))
			has_digit = 1;
		else if (str[i] == '.')
		{
			if (has_dot)
				return 0;
			has_dot = 1;
		}
		else
			return 0;
		i++;
	}
	return (has_digit);
}
