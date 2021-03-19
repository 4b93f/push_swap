/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:20:05 by chly-huc          #+#    #+#             */
/*   Updated: 2021/03/19 20:00:04 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"


typedef struct		s_stack
{
	struct s_stack	*next;
	int				content;
}					t_stack_a;

typedef struct  s_ps
{
    int     big;
    int     size;
	int		stock;
    int     little;
    int    		big_index;
    t_stack_a	*stack_a;
    t_stack_a	*stack_b;
	int		little_index;
}               t_ps;

enum            e_error
{
    LESS_ARG,    
};

void	ft_ra(t_ps *ps);
void	ft_sa(t_ps *ps);
void	ft_pb(t_ps *ps);
void	ft_rra(t_ps *ps);
void	ft_three(t_ps *ps);
t_ps        *ft_malloc_ps(void);
int         ft_sorted(t_ps *ps);
void	find_little_big(t_ps *ps);
t_stack_a	*ft_stacknew(int content);
t_stack_a	*ft_stacklast(t_stack_a *lst);
void	ft_stackadd_front(t_stack_a **alst, t_stack_a *new);
void	ft_under_twenty(t_ps *ps);
void	ft_stackadd_back(t_stack_a **alst, t_stack_a *new);
void	ft_print_stack(t_stack_a *lst);
void ft_pa(t_ps *ps);
int		ft_sorted(t_ps *ps);
void	ft_above_twenty(t_ps *ps);