#include "pushswap.h"

int	check_limit(long num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

int check_num(char *num)
{
	while (*num)
	{
		if (ft_isdigit((int)*num))
			num++;
		else
			return (0);
	}
	return (1);
}

int check_num_arr(char **str)
{
	while (*str)
	{
		if (check_num(*str))
			str++;
		else
			return (0);
	}
	return (1);
}

t_hld *from_str(char *str, t_hld *hld)
{
	char	**split;
	char	**split_st;
	long	l_val;
	int		cont;

	cont = 1;
	split = ft_split(str, ' ');
	split_st = split;
	if (!check_num_arr(split))
		cont = ft_err_int("non num found");
	while (split && cont)
	{
		l_val = ft_atol(*split);
		if (check_limit(l_val))
			cont = stk_push(hld, (int)l_val);
		else
			cont = ft_err_int("digit not within limits");
		split++;
	}
	if (!cont)
		return (free_exit_hld(hld, split_st));
	return (hld);
}

t_hld *from_arr(char **arr, t_hld *hld)
{
	long	l_val;
	int		cont;

	cont = 1;
	if (!check_num_arr(arr))
		cont = ft_err_int("non num found");
	while (*arr && cont)
	{
		l_val = ft_atol(*arr);
		if (check_limit(l_val))
			cont = stk_push(hld, (int)l_val,-1);
		else
			cont = ft_err_int("digit not within limits");
		arr++;
	}
	if (!cont)
	{
		free_hld(hld);
		return (NULL);
	}
	return (hld);
}

t_llst	*min_val(t_hld *hld)
{
	t_llst	*node;
	t_llst	*min_node;
	int		min;

	node = hld -> head;
	min_node = node;
	while (node)
	{
		if (min_node -> val > node -> val && node -> idx != -1)
			min_node = node;
		node = node -> next;
	}
	return (min_node);
}


void	init_idx(t_hld *hld)
{
	t_llst	*node;
	t_llst	*min_node;
	int		idx;
	int		lim;

	idx = 0;
	lim = hld -> size - 1;
	node = hld -> head;
	while (node && idx < lim)
	{
		min_node = min_val(hld);
		min_node -> idx = idx;
		idx++;
		node = node -> next;
	}
}


t_hld	*parse_args(int argc, char **argv)
{
	t_hld	*hld;

	hld = (t_hld *) malloc(sizeof(t_hld));
	if (!hld)
		return (NULL);
	argv++;
	if (argc == 2)
		hld = from_str(*argv, hld);		
	if (argc > 2)
		hld = from_arr(argv, hld);
	return (hld);
}
