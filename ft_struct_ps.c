/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shyrno <shyrno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:02:42 by chly-huc          #+#    #+#             */
/*   Updated: 2021/03/12 19:39:07 by shyrno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	ft_create_ps(void)
{
	t_ps ps;

	ps.pile_a = NULL;
	ps.pile_b = NULL;
	ps.size = 0;
	ps.actual = 0;
	ps.little = 0;
	ps.big = 0;
	ps.i;
	return (ps);
}

t_ps	*ft_malloc_ps(void)
{
	t_ps *malloc_ps;

	if (!(malloc_ps = malloc(sizeof(t_ps))))
		return (NULL);
	*malloc_ps = ft_create_ps();
	return (malloc_ps);
}
