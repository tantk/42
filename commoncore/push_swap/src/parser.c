#include "pushswap.h"

int	check_limit(long num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

int check_num(char *num)
{
	while (num)
	{
		if ft_isdigit(int(*num))
			num++;
		else
			return (0);
	}
	return (1);
}

int check_num_arr(char **str)
{
	while (str)
	{
		if check_num(*str)
			str++;
		else
			return (0);
	}
	return (1);
}

t_hld *from_str(char *str)
{
	char	**split;
	long	l_val;
	t_hld	*hld;

	hld = (t_hld *) malloc(sizeof(t_hld));
	if (!hld)
		return (NULL);
	split = ft_split(s, ' ');
	if !check_num_arr(split)
		//free and return NULL
		return (NULL);
	while (split)
	{
		l_val = ft_atol(*split);
		if check_limit(l_val)
			stk_add(hld, int(l_val));
		else
			//free and return NULL
			return (NULL);
		split++;
	}
}

t_hld *from_arr(char **arr)
{
	t_hld	*hld;
	long	l_val;

	hld = (t_hld *) malloc(sizeof(t_hld));
	if(!hld)
		return (NULL);
	if !check_num_arr(arr)
		//free and return NULL
		return (NULL);
	while (arr)
	{
		l_val = ft_atol(*arr);
		if check_limit(l_val)
			stk_add(hld, int(l_val));
		else
			//free and return NULL
			return (NULL);
		arr++;
	}
}


t_hld *parse_args(int argc, char **argv)
{
	t_hld	*hld;

	argv++;
	if (argc == 2)
		hld = from_str(*argv);		

	if (argc > 2)
		hld = from_arr(argv);

}
