
#include "pushswap.h"

void	ft_err_exit(char *msg)
{
	ft_printf_err("Error:  %s",msg);
	exit(0);
}

int		ft_err_int(char *msg)
{
	ft_printf_err("Error: %s",msg);
	return (0);
}


