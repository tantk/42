/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:01:17 by titan             #+#    #+#             */
/*   Updated: 2024/05/02 00:20:43 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_llst
{
	int				val;
	int				rk;
	struct s_llst	*next;
}	t_llst;

typedef struct s_lst_holder
{
	t_llst			*head;
	t_llst			*last;
	unsigned int	size;
	unsigned int	max_rk;
}	t_hld;

int		stk_rev_ins(t_hld *hld, int val, int rk);
int		stk_pop(t_hld *hld);
int		stk_push(t_hld *hld, int val, int rk);
void	free_split(char **split);
void	free_hld(t_hld *hld);
void	*free_exit_hld(t_hld *hld, char **split);

int		check_limit(long num);
int		check_num(char *num);
int		check_num_arr(char **str);
t_llst	*first_node(t_hld *hld);
t_llst	*min_val(t_hld *hld);

t_hld	*parse_args(int argc, char **argv);
t_hld	*init_hld(void);

t_llst	*find_slst(t_hld *hld);
int		push_oth(t_hld *a, t_hld *b);
int		rotate(t_hld *hld);
int		rev_rotate(t_hld *hld);
int		swap(t_hld *hld);

void	pa(t_hld *a, t_hld *b);
void	pb(t_hld *a, t_hld *b);
void	ra(t_hld *a);
void	rb(t_hld *b);
void	sa(t_hld *a);
void	rra(t_hld *a);

int		is_sorted(t_hld *hld);
void	sort_2(t_hld *hld);
void	sort_3(t_hld *hld);
void	sort_4(t_hld *a, t_hld *b, int find);
void	sort_5(t_hld *a, t_hld *b);
void	rdx_srt(t_hld *a, t_hld *b);

void	ft_err_exit(char *msg);
int		ft_err_int(char *msg);
#endif
