float ft_atof(char *str)
{
	int i;
	float result;
	int sign;
	float divisor;
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
	while (str[i] && ft_isdigit(str[i]))
	{
		result = result * 10.0f + (str[i] - 48);
		i++;
	}	
	if (str[i] == '.')
	{
		i++;
		while (str[i] && ft_isdigit(str[i]))
		{
			result = result * 10.0f + (str[i] - 48);
			divisor *= 10.0f;
			i++;
		}
	}
	return (result * sign / divisor);
}
