int	is_power_of_2(unsigned int n)
{
	int i = 1;
	while (i < n/2 || i == 1)
	{
		if (n/i == i)
			return (1);
		i++;
	}
	return (0);
}
