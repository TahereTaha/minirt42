void	check_overflow_int(char *str)
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
			/*error message and exit*/
		result = result * 10 + (str[i] - 48);
		i++;
	}
}
