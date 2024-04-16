#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_llst{
    int             val;
    struct s_llst   *next;
}   t_llst;

typedef struct s_lst_holder{
	t_llst			*head;
	t_llst			*last;
	unsigned int	size;
    int             check;
}	t_hld;


int stk_add(t_hld *hld, int val);

#endif
