/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:02:42 by chly-huc          #+#    #+#             */
/*   Updated: 2021/03/14 18:31:54 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	ft_create_ps(void)
{
	t_ps ps;

	ps.size = 0;
	ps.stock = 0;
	ps.little = 0;
	ps.big = 0;
	ps.stack_a = NULL;
	ps.stack_b = NULL;
	ps.big_index = 0;
	ps.little_index = 0;
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
