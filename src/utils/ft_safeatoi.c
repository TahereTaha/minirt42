int	check_overflow_atoi(long result)
{
	if (result > INT_MAX)
		return (INT_MAX);
	if (result < INT_MIN)
		return (INT_MIN)
	return ((int)result);

}

int	ft_atoi(const char *str)
{
	int	i;
	long	result;
	int	sign;

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
		result = result * 10 + (str[i] - 48);
		i++;
	}
	result = result * sign;
	return (check_overflow_atoi(result));
}
