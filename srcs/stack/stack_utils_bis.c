/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:14:17 by chly-huc          #+#    #+#             */
/*   Updated: 2021/04/29 17:24:59 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_stacksize(t_stack_a *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_stackclear(t_stack_a **lst, void (*del)(void *))
{
	t_stack_a	*tmp;

	if (lst || del)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			free(*lst);
			*lst = tmp;
		}
	}
}

t_stack_a	*del_one(t_stack_a *lst)
{
	t_stack_a	*ptr_lst;

	if (!lst)
		return (NULL);
	ptr_lst = lst;
	lst = lst->next;
	free(ptr_lst);
	return (lst);
}
