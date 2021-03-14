/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 22:40:14 by shyrno            #+#    #+#             */
/*   Updated: 2021/03/14 19:06:00 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_sorted(t_ps *ps)
{
	t_stack_a *ptr_stack_a;

	ptr_stack_a = ps->stack_a;
	//printf("ptr\n");
	while (ptr_stack_a)
	{
		//printf("<%d %d>\n", ptr_stack_a->content, ptr_stack_a->next->content);
		if (ptr_stack_a->next != 0 && ptr_stack_a->content >
		ptr_stack_a->next->content)
			return (0);
		ptr_stack_a = ptr_stack_a->next;
	}
	return (1);
}

void	find_little_big(t_ps *ps)
{
	int			i;
	t_stack_a	*ptr_stack_a;

	i = 0;
	ptr_stack_a = ps->stack_a;
	ps->little = ptr_stack_a->content;
	while (ptr_stack_a)
	{
		if (ps->big < ptr_stack_a->content)
		{
			ps->big = ptr_stack_a->content;
			ps->big_index = i;
		}
		if (ps->little > ptr_stack_a->content)
		{
			ps->little = ptr_stack_a->content;
			ps->little_index = i;
		}
		ptr_stack_a = ptr_stack_a->next;
		i++;
	}
	return ;
}

void	ft_sa(t_ps *ps)
{
	t_stack_a *ptr_stack_a;

	ptr_stack_a = ps->stack_a;
	ps->stock = ptr_stack_a->content;
	ptr_stack_a->content = ptr_stack_a->next->content;
	ptr_stack_a = ptr_stack_a->next;
	ptr_stack_a->content = ps->stock;
}

void	ft_ra(t_ps *ps)
{
	t_stack_a *ptr_stack_a;

	ptr_stack_a = ps->stack_a;
	ps->stock = ptr_stack_a->content;
	ptr_stack_a->content = ptr_stack_a->next->content;
	ptr_stack_a = ptr_stack_a->next;
	ptr_stack_a->content = ps->stock;
	ps->stock = ptr_stack_a->content;
	ptr_stack_a->content = ptr_stack_a->next->content;
	ptr_stack_a = ptr_stack_a->next;
	ptr_stack_a->content = ps->stock;
}

void ft_rra(t_ps *ps)
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
}

void	ft_swap(t_ps *ps)
{
	find_little_big(ps);
	if (!ft_sorted(ps))
	{
		if (ps->big_index == 2 && ps->little_index == 1)
			ft_sa(ps);
		else if (ps->big_index == 0 && ps->little_index == 1) 
			ft_ra(ps);
		else if (ps->big_index == 1 && ps->little_index == 0)
		{
			ft_sa(ps);
			ft_ra(ps);
		}
		else if (ps->big_index == 1 && ps->little_index == 2)
			ft_rra(ps);
		/*
		else if (ps->pile_a[0] == ps->big && ps->pile_a[2] == ps->little)
		{
			ft_sa(ps, 0, 1);
			ft_rra(ps);
		}
	}
	*/
	}
	return ;
}
void ft_three(t_ps *ps)
{
	ft_swap(ps);        
}

void ft_under_fifty(t_ps *ps)
{
	find_little_big(ps);
}
