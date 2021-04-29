/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:05:06 by chly-huc          #+#    #+#             */
/*   Updated: 2021/04/29 17:24:27 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_scale(t_ps *ps)
{
	if (ps->size >= 1000)
		ps->nbr_list = 18;
	else if (ps->size >= 500 && ps->size < 1000)
		ps->nbr_list = 11;
	else if (ps->size >= 100 && ps->size < 500)
		ps->nbr_list = 6;
	else if (ps->size < 100)
		ps->nbr_list = 4;
}

void	ft_create_tablist(t_ps *ps)
{
	int			i;
	int			j;
	int			len;
	t_stack_a	*tmp;

	i = 0;
	j = 0;
	tmp = ps->sorted_lst;
	len = ps->size / ps->nbr_list;
	if (ps->size % ps->nbr_list != 0)
		len++;
	ps->tab_lst = malloc(sizeof(int *) * ps->nbr_list);
	if (!ps->tab_lst)
		ft_error(MALLOC_ERROR, ps);
	ps->lst_size = malloc(sizeof(int) * ps->nbr_list);
	if (!ps->lst_size)
		ft_error(MALLOC_ERROR, ps);
	while (i < ps->nbr_list)
	{
		ps->tab_lst[i] = fill_tab_lst(ps, len, i);
		i++;
	}
	ft_stackclear(&tmp, free);
}

int	*fill_tab_lst(t_ps *ps, int len, int size)
{
	int	i;
	int	*tab_lst;

	i = 0;
	tab_lst = malloc(sizeof(int) * (len + 1));
	if (!tab_lst)
		ft_error(MALLOC_ERROR, ps);
	while (i < len || !ps->sorted_lst)
	{
		if (!ps->sorted_lst->next && ++i)
			break ;
		tab_lst[i] = ps->sorted_lst->content;
		ps->sorted_lst = ps->sorted_lst->next;
		i++;
	}
	ps->lst_size[size] = i;
	return (tab_lst);
}
