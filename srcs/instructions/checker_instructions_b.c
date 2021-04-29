/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instructions_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:53:47 by chly-huc          #+#    #+#             */
/*   Updated: 2021/04/29 17:23:24 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	ft_checker_rb(t_ps *ps)
{
	ps->ptr_stack_b = ps->stack_b;
	ps->stock = ps->ptr_stack_b->content;
	while (ps->ptr_stack_b->next)
	{
		ps->ptr_stack_b->content = ps->ptr_stack_b->next->content;
		ps->ptr_stack_b = ps->ptr_stack_b->next;
	}
	ps->ptr_stack_b->content = ps->stock;
}

void	ft_checker_rrb(t_ps *ps)
{
	t_stack_a	*first;

	first = ps->stack_b;
	ps->ptr_stack_b = ps->stack_b;
	ps->ptr_stack_b = ps->ptr_stack_b->next;
	while (ps->ptr_stack_b)
	{
		ps->stock = ps->ptr_stack_b->content;
		ps->ptr_stack_b->content = first->content;
		first->content = ps->stock;
		ps->ptr_stack_b = ps->ptr_stack_b->next;
	}
}

void	ft_checker_pb(t_ps *ps)
{
	ft_stackadd_front(&ps->stack_b, ft_stacknew(ps->stack_a->content));
	ps->stack_a = del_one(ps->stack_a);
	ps->b_size++;
}
