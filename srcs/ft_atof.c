
static char	*skip_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] != ' ' && str[i] != '\f' && str[i] != '\n')
			if (str[i] != '\r' && str[i] != '\t' && str[i] != '\v')
				return ((char *) &str[i]);
		i++;
	}
	return ((char *) str);
}

static int	check_signal_number(char c)
{
	if (c == '+' || (c >= '0' && c <= '9'))
		return (1);
	else if (c == '-')
		return (-1);
	else
		return (0);
}

static double	get_fraction(char *str)
{
	double	fraction;
	int	i;
	int	j;
	int	div;
	double	tmp;

	i = 0;
	j = -1;
	fraction = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	div = 10;
	while (++j < i && str[j] >= '0' && str[j] <= '9')
	{
		tmp = str[j] - 0x30;
		fraction = fraction + (tmp / div);
		div = div * 10;
	}
	return (fraction);
}

static double	get_numbers(char *str)
{
	int	i;
	int	j;
	double	nb;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	nb = 0;
	j = -1;
	while (++j < i && str[j] >= '0' && str[j] <= '9')
		nb = (nb * 10) + (str[j] - 0x30);
	if (str[i] == ',' || str[i] == '.')
		nb = nb + get_fraction(&str[i+1]);
	return (nb);
}

double	ft_atof(const char *str)
{
	char	*new_addr;
	int	signal;
	double	nb;

	if (!str)
		return (0);
	new_addr = skip_spaces(str);
	signal = check_signal_number(new_addr[0]);
	if (!signal)
		return (0);
	else
	{
		if (new_addr[0] == '-' || new_addr[0] == '+')
			new_addr++;
		nb = get_numbers(new_addr);
		if (signal == -1)
			return (nb * signal);
		else
			return (nb);
	}
}
