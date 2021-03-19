/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:08:00 by chly-huc          #+#    #+#             */
/*   Updated: 2021/03/19 20:10:24 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack_a	*del_one(t_stack_a *lst)
{
	t_stack_a *ptr_lst;
	if (!lst)
		return (NULL);
	ptr_lst = lst;
	lst = lst->next;
	free(ptr_lst);
	return (lst);
}

int		ft_sorted(t_ps *ps)
{
	t_stack_a *ptr_stack_a;

	ptr_stack_a = ps->stack_a;
	while (ptr_stack_a)
	{
		if (ptr_stack_a->next != 0 && ptr_stack_a->content >
		ptr_stack_a->next->content)
			return (0);
		ptr_stack_a = ptr_stack_a->next;
	}
	return (1);
}


void	ft_sa(t_ps *ps)
{
	t_stack_a *ptr_stack_a;

	ptr_stack_a = ps->stack_a;
	ps->stock = ptr_stack_a->content;
	if (ptr_stack_a->next)
	{
		ptr_stack_a->content = ptr_stack_a->next->content;
		ptr_stack_a = ptr_stack_a->next;
		ptr_stack_a->content = ps->stock;
	}
	//printf("sa\n");
}

void	ft_ra(t_ps *ps)
{
	t_stack_a *ptr_stack_a;

	ptr_stack_a = ps->stack_a;
	ps->stock = ptr_stack_a->content;
	while (ptr_stack_a->next)
	{
		ptr_stack_a->content = ptr_stack_a->next->content;
		ptr_stack_a = ptr_stack_a->next;
	}
	ptr_stack_a->content = ps->stock;
	//printf("ra\n");
}

void	ft_rra(t_ps *ps)
{
	t_stack_a *ptr_stack_a;
	t_stack_a *first;

	first = ps->stack_a;
	ptr_stack_a = ps->stack_a;
	while (ptr_stack_a->next->next)
	{
		ps->stock = ptr_stack_a->next->content;
		ptr_stack_a->next->content = ptr_stack_a->content;
		ptr_stack_a->content = ps->stock;
		ptr_stack_a = ptr_stack_a->next;
	}
	ps->stock = first->content;
	first->content = ptr_stack_a->next->content;
	ptr_stack_a->next->content = ps->stock;
	//printf("rra\n");
}


void	ft_pb(t_ps *ps)
{
	ft_stackadd_front(&ps->stack_b, ft_stacknew(ps->stack_a->content));
	ps->stack_a = del_one(ps->stack_a);
}

void ft_pa_checker(t_ps *ps)
{
	if (!ps->stack_b)
		ps->stack_a = ft_stacknew((ps->stack_b->content));
	ft_stackadd_front(&ps->stack_a, ft_stacknew(ps->stack_b->content));
	ps->stack_b = ps->stack_b->next;
}
