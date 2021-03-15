/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:14:17 by chly-huc          #+#    #+#             */
/*   Updated: 2021/03/15 18:42:02 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ft_stackadd_back(t_stack_a **alst, t_stack_a *new)
{
	if (!alst || !new)
		return ;
	if (alst && *alst)
		ft_lstlast(*alst)->next = new;
	else if (alst)
		*alst = new;
}
