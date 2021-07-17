/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 20:48:44 by chly-huc          #+#    #+#             */
/*   Updated: 2021/07/16 12:55:11 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_sorted(t_ps *ps)
{
	ps->ptr_stack_a = ps->stack_a;
	while (ps->ptr_stack_a)
	{
		if (ps->ptr_stack_a->next && ps->ptr_stack_a->next != 0
			&& ps->ptr_stack_a->content > ps->ptr_stack_a->next->content)
			return (0);
		ps->ptr_stack_a = ps->ptr_stack_a->next;
	}
	return (1);
}

int	ft_find_in_list(int content, int *lst, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (content == lst[i])
			return (1);
	}
	return (0);
}

void	find_little_big(t_ps *ps)
{
	int			i;

	i = 0;
	ps->ptr_stack_a = ps->stack_a;
	if (!ps->ptr_stack_a)
		return ;
	ps->little = ps->ptr_stack_a->content;
	ps->big = ps->ptr_stack_a->content;
	while (ps->ptr_stack_a)
	{
		if (ps->big <= ps->ptr_stack_a->content)
		{
			ps->big = ps->ptr_stack_a->content;
			ps->big_index = i;
		}
		if (ps->little >= ps->ptr_stack_a->content)
		{
			ps->little = ps->ptr_stack_a->content;
			ps->little_index = i;
		}
		ps->ptr_stack_a = ps->ptr_stack_a->next;
		i++;
	}
	return ;
}

static int	check_number(char *argv)
{
	int	i;

	i = -1;
	if (ft_atoli(argv) > INT32_MAX || ft_atoli(argv) < -214743648)
		return (0);
	while (argv[++i])
	{
		if (!ft_isdigit(argv[i]))
		{
			if (!(argv[i] == '-' && argv[i + 1] && ft_isdigit(argv[i + 1])))
				return (0);
		}
	}
	return (1);
}

int	find_duplicate(char **argv, t_ps *ps)
{
	int		i;
	int		j;
	int		len;
	char	*stock;

	i = 0;
	j = 0;
	len = 0;
	while (argv[++i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (!check_number(argv[i]) || !check_number(argv[j]))
				ft_error(ERROR, ps);
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				ft_error(ERROR, ps);
			j++;
		}
	}
	return (1);
}
