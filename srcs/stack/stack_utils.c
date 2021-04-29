/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 20:26:27 by chly-huc          #+#    #+#             */
/*   Updated: 2021/04/29 17:25:08 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack_a	*ft_create_stack(t_ps *ps, char **argv)
{
	t_stack_a	*list;
	int			i;

	i = 1;
	list = ft_stacknew(ft_atoi(argv[i]));
	if (!list && argv)
		ft_error(MALLOC_ERROR, ps);
	while (argv[++i])
		ft_stackadd_back(&list, ft_stacknew(ft_atoi(argv[i])));
	return (list);
}

t_stack_a	*ft_stacknew(int content)
{
	t_stack_a	*newcontent;

	newcontent = malloc(sizeof(t_stack_a *));
	if (!newcontent)
		return (NULL);
	newcontent->content = content;
	newcontent->next = NULL;
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
