/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:20:05 by chly-huc          #+#    #+#             */
/*   Updated: 2021/04/29 17:31:05 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "limits.h"

typedef struct s_stack
{
	struct s_stack	*next;
	int				content;
}				t_stack_a;

typedef struct s_ps
{
	int			big;
	int			size;
	int			stock;
	int			little;
	int			b_size;
	t_stack_a	*stack_b;
	int			nbr_list;
	t_stack_a	*stack_a;
	int			big_index;
	int			**tab_lst;
	int			*lst_size;
	int			hold_first;
	int			hold_second;
	t_stack_a	*sorted_lst;
	int			little_index;
	t_stack_a	*ptr_stack_b;
	t_stack_a	*ptr_stack_a;
}					t_ps;

enum			e_error
{
	MALLOC_ERROR,
	ERROR
};

void		ft_ra(t_ps *ps);
void		ft_sa(t_ps *ps);
void		ft_pb(t_ps *ps);
void		ft_pa(t_ps *ps);
void		ft_rb(t_ps *ps);
void		ft_rra(t_ps *ps);
void		ft_rrb(t_ps *ps);
void		ft_exit(t_ps *ps);
void		ft_scale(t_ps *ps);
void		ft_three(t_ps *ps);
int			ft_sorted(t_ps *ps);
t_ps		*ft_malloc_ps(void);
t_stack_a	*del_one(t_stack_a *lst);
void		ft_under_fifty(t_ps *ps);
void		ft_above_twenty(t_ps *ps);
void		find_little_big(t_ps *ps);
t_stack_a	*ft_stacknew(int content);
void		ft_error(int ret, t_ps*ps);
void		ft_create_tablist(t_ps *ps);
int			ft_stacksize(t_stack_a *lst);
t_stack_a	*ft_stacklast(t_stack_a *lst);
void		ft_big(t_ps *ps, int i, int j);
int			find_duplicate(char **argv, t_ps *ps);
t_stack_a	*ft_create_stack(t_ps *ps, char **argv);
int			*fill_tab_lst(t_ps *ps, int len, int size);
void		handle_error(t_ps *ps, int argc, char **argv);
int			ft_find_in_list(int content, int *lst, int size);
void		ft_stackclear(t_stack_a **lst, void (*del)(void *));
void		ft_stackadd_back(t_stack_a **alst, t_stack_a *new);
void		ft_stackadd_front(t_stack_a **alst, t_stack_a *new);

#endif