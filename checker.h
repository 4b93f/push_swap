/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:50:16 by chly-huc          #+#    #+#             */
/*   Updated: 2021/03/17 20:21:48 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/libft.h"

#include "get_next_line/get_next_line.h"

typedef struct		s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack_a;

typedef struct  s_ps
{
	int		stock;
    int     size;
    int     little;
    int     big;
    int     big_index;
	int		little_index;
    t_stack_a *stack_a;
    t_stack_a *stack_b;
}               t_ps;

enum            e_error
{
    LESS_ARG,    
};

t_ps        *ft_malloc_ps(void);
int         ft_sorted(t_ps *ps);
t_stack_a	*ft_stacknew(int content);
t_stack_a	*ft_stacklast(t_stack_a *lst);
void	ft_stackadd_back(t_stack_a **alst, t_stack_a *new);
void	ft_print_stack(t_stack_a *lst);
void	ft_pb(t_ps *ps);
void	ft_rra(t_ps *ps);
void	ft_ra(t_ps *ps);
void	ft_sa(t_ps *ps);
int		ft_sorted(t_ps *ps);