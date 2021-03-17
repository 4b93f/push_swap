/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 22:40:14 by shyrno            #+#    #+#             */
/*   Updated: 2021/03/17 21:12:25 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	find_little_big(t_ps *ps)
{
	int			i;
	t_stack_a	*ptr_stack_a;

	i = 0;
	ptr_stack_a = ps->stack_a;
	if (!ptr_stack_a)
		return ;
	ps->little = ptr_stack_a->content;
	while (ptr_stack_a)
	{
		if (ps->big <= ptr_stack_a->content)
		{
			ps->big = ptr_stack_a->content;
			ps->big_index = i;
		}
		if (ps->little >= ptr_stack_a->content)
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
	printf("sa\n");
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
	printf("ra\n");
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
	printf("rra\n");
}

void	ft_three(t_ps *ps)
{
	if (!ft_sorted(ps))
	{
		printf("%d %d\n", ps->big_index, ps->little_index);
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
		else if (ps->big_index == 0 && ps->little_index == 2)
		{
			ft_sa(ps);
			ft_rra(ps);
		}
	}
	return ;
}

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

void	ft_pb(t_ps *ps)
{
	ft_stackadd_back(&ps->stack_b, ft_stacknew(ps->stack_a->content));
	ps->stack_a = del_one(ps->stack_a);
	printf("pb\n");
}

void	ft_under_fifty(t_ps *ps)
{
	double divid;

	if (!ft_sorted(ps))
	{
		while (ps->stack_a)
		{
			if (ps->size == 3)
			{
				ft_three(ps);
				return ;
			}
			while (ps->little_index != 0)
			{
				find_little_big(ps);
				if (ps->little_index == 1)
					ft_sa(ps);
				else
				{
					divid = ps->little_index;
					if (divid / 2 >= 0.5)
						ft_rra(ps);
					else
						ft_ra(ps);
				}
				find_little_big(ps);
			}
			if (ps->little_index == 0)
			{
				ft_pb(ps);
				ps->size--;
				find_little_big(ps);
			}
		}
	}
}
