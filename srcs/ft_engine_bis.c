/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 20:57:09 by chly-huc          #+#    #+#             */
/*   Updated: 2021/04/29 17:24:14 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_three(t_ps *ps)
{
	if (!ft_sorted(ps))
	{
		if (ps->big_index == 2 && ps->little_index == 1)
			ft_sa(ps);
		else if (ps->big_index == 0 && ps->little_index == 1)
		{
			ft_ra(ps);
		}
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

static void	three_left(t_ps *ps)
{
	if (ps->size == 3)
	{
		ft_three(ps);
		while (ps->stack_b)
		{
			ft_pa(ps);
			if (!ps->stack_b->next)
			{
				ft_pa(ps);
				break ;
			}
		}
		if (ft_sorted(ps))
			ft_exit(0);
	}
}

void	up_and_down_algo(t_ps *ps)
{
	double	divid;

	while (ps->little_index != 0)
	{
		find_little_big(ps);
		divid = ps->little_index;
		if (divid / 2 > 0.5)
			ft_rra(ps);
		else
			ft_ra(ps);
		find_little_big(ps);
		if (ft_sorted(ps))
			return ;
	}
}

void	ft_under_fifty(t_ps *ps)
{
	if (!ft_sorted(ps))
	{
		ps->ptr_stack_a = ps->stack_a;
		while (ps->ptr_stack_a)
		{
			three_left(ps);
			up_and_down_algo(ps);
			if (ft_sorted(ps))
				return ;
			if (ps->little_index == 0)
			{
				ft_pb(ps);
				find_little_big(ps);
			}
			ps->ptr_stack_a = ps->stack_a;
		}
	}
}
