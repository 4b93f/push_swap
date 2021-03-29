/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:14:17 by chly-huc          #+#    #+#             */
/*   Updated: 2021/03/19 17:53:18 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_stackclear(t_stack_a **lst, void (*del)(void *))
{
	t_stack_a *tmp;

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

void	ft_print_stack(t_stack_a *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		printf("{%d}\n", lst->content);
		lst = lst->next;
	}
}

t_stack_a	*ft_stacknew(int content)
{
	t_stack_a *newcontent;

	if (!(newcontent = malloc(sizeof(t_stack_a))))
		return (0);
	newcontent->content = content;
	//printf("newcontent dans stacknew=%d\n", newcontent->content);
	newcontent->next = 0;
	return (newcontent);
}

t_stack_a	*ft_stacklast(t_stack_a *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_stackadd_front(t_stack_a **alst, t_stack_a *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}

void	ft_stackadd_back(t_stack_a **alst, t_stack_a *new)
{
	if (!alst || !new)
		return ;
	if (alst && *alst)
		ft_stacklast(*alst)->next = new;
	else if (alst)
		*alst = new;
}
