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
	unsigned int	max_idx;
}	t_hld;


int		stk_rev_ins(t_hld *hld, int val, int idx);
int		stk_pop(t_hld *hld);
int		stk_push(t_hld *hld, int val, int idx);
void	free_split(char **split);
void	free_hld(t_hld *hld);
void	*free_exit_hld(t_hld *hld, char **split);
t_hld	*parse_args(int argc, char **argv);
t_hld	*empty_stk();
int		push_oth(t_hld *a, t_hld *b);
int		rotate(t_hld *hld);

void    pa(t_hld *a, t_hld *b);
void    pb(t_hld *a, t_hld *b);
void    ra(t_hld *a);
void    rb(t_hld *b);

int		is_sorted(t_hld *hld);
void	rdx_srt(t_hld *a, t_hld *b);

void	ft_err_exit(char *msg);
int		ft_err_int(char *msg);
#endif
