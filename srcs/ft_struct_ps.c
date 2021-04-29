/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:02:42 by chly-huc          #+#    #+#             */
/*   Updated: 2021/04/29 17:24:21 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ps	ft_create_ps(void)
{
	t_ps	ps;

	ps.big = 0;
	ps.size = 0;
	ps.stock = 0;
	ps.little = 0;
	ps.big_index = 0;
	ps.little_index = 0;
	ps.tab_lst = NULL;
	ps.stack_b = NULL;
	ps.stack_a = NULL;
	ps.nbr_list = 0;
	ps.ptr_stack_a = NULL;
	ps.sorted_lst = NULL;
	ps.ptr_stack_b = NULL;
	ps.lst_size = NULL;
	ps.hold_first = 0;
	ps.hold_second = 0;
	ps.b_size = 0;
	return (ps);
}

t_ps	*ft_malloc_ps(void)
{
	t_ps	*malloc_ps;

	malloc_ps = malloc(sizeof(t_ps));
	if (!malloc_ps)
		return (NULL);
	*malloc_ps = ft_create_ps();
	return (malloc_ps);
}
