/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 20:45:27 by chly-huc          #+#    #+#             */
/*   Updated: 2021/04/29 17:23:45 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sa(t_ps *ps)
{
	ps->ptr_stack_a = ps->stack_a;
	ps->stock = ps->ptr_stack_a->content;
	if (ps->ptr_stack_a->next)
	{
		ps->ptr_stack_a->content = ps->ptr_stack_a->next->content;
		ps->ptr_stack_a = ps->ptr_stack_a->next;
		ps->ptr_stack_a->content = ps->stock;
	}
	printf("sa\n");
}

void	ft_ra(t_ps *ps)
{
	ps->ptr_stack_a = ps->stack_a;
	ps->stock = ps->ptr_stack_a->content;
	while (ps->ptr_stack_a->next)
	{
		ps->ptr_stack_a->content = ps->ptr_stack_a->next->content;
		ps->ptr_stack_a = ps->ptr_stack_a->next;
	}
	ps->ptr_stack_a->content = ps->stock;
	printf("ra\n");
}

void	ft_rra(t_ps *ps)
{
	t_stack_a	*first;

	first = ps->stack_a;
	ps->ptr_stack_a = ps->stack_a;
	ps->ptr_stack_a = ps->ptr_stack_a->next;
	while (ps->ptr_stack_a)
	{
		ps->stock = ps->ptr_stack_a->content;
		ps->ptr_stack_a->content = first->content;
		first->content = ps->stock;
		ps->ptr_stack_a = ps->ptr_stack_a->next;
	}
	printf("rra\n");
}

void	ft_pa(t_ps *ps)
{
	if (!ps->stack_b)
		ps->stack_a = ft_stacknew((ps->stack_b->content));
	ft_stackadd_front(&ps->stack_a, ft_stacknew(ps->stack_b->content));
	ps->stack_b = del_one(ps->stack_b);
	printf("pa\n");
	ps->b_size--;
}
