/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 22:40:14 by shyrno            #+#    #+#             */
/*   Updated: 2021/04/29 17:24:17 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_biggest(t_ps *ps)
{
	int		stock;
	int		i;
	int		index;

	index = 0;
	ps->ptr_stack_b = ps->stack_b;
	stock = ps->ptr_stack_b->content;
	if (ps->ptr_stack_b)
		ps->ptr_stack_b = ps->stack_b->next;
	i = 1;
	while (ps->ptr_stack_b)
	{
		if (stock < ps->ptr_stack_b->content)
		{
			index = i;
			stock = ps->ptr_stack_b->content;
		}
		ps->ptr_stack_b = ps->ptr_stack_b->next;
		i++;
	}
	return (index);
}

static void	ft_to_stack_a(t_ps *ps, int i)
{
	ps->ptr_stack_b = ps->stack_b;
	ps->b_size = ft_stacksize(ps->ptr_stack_b);
	while (ps->ptr_stack_b)
	{
		i = get_biggest(ps);
		if (i < ps->b_size - i)
			while (i-- > 0)
				ft_rb(ps);
		else
		{
			i = ps->b_size - i;
			while (i-- > 0)
				ft_rrb(ps);
		}
		ft_pa(ps);
		ps->ptr_stack_b = ps->stack_b;
	}
}

void	ft_big(t_ps *ps, int i, int j)
{
	while (ps->ptr_stack_a)
	{
		if (!ps->ptr_stack_a->next)
		{
			ft_pb(ps);
			break ;
		}
		if (ft_find_in_list(ps->ptr_stack_a->content, ps->tab_lst[i],
				ps->lst_size[i]))
		{
			ft_pb(ps);
			j++;
		}
		else
			ft_ra(ps);
		if (j >= ps->lst_size[i])
		{
			j = 0;
			i++;
		}
		ps->ptr_stack_a = ps->stack_a;
	}
	ft_to_stack_a(ps, i);
}
