#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "limits.h"


typedef struct s_llst{
    int             val;
	int				idx;
    struct s_llst   *next;
}   t_llst;

typedef struct s_lst_holder{
	t_llst			*head;
	t_llst			*last;
	unsigned int	size;
    int             check;
}	t_hld;


int		stk_add(t_hld *hld, int val);
int		stk_pop(t_hld *hld);
int		stk_push(t_hld *hld, int val);
void	free_split(char **split);
void	free_hld(t_hld *hld);
void	*free_exit_hld(t_hld *hld, char **split);
t_hld	*parse_args(int argc, char **argv);
int		push_oth(t_hld *a, t_hld *b);
int		rotate(t_hld *hld);

void	ft_err_exit(char *msg);
int		ft_err_int(char *msg);
#endif
