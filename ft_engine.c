/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 22:40:14 by shyrno            #+#    #+#             */
/*   Updated: 2021/03/19 20:22:48 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_sorted(t_ps *ps)
{
	t_stack_a *ptr_stack_a;

	ptr_stack_a = ps->stack_a;
	while (ptr_stack_a)
	{
		if (ptr_stack_a->next != 0 && ptr_stack_a->content >
		ptr_stack_a->next->content)
			return (0);
		ptr_stack_a = ptr_stack_a->next;
	}
	return (1);
}

void	find_little_big(t_ps *ps)
{
	int			i;
	t_stack_a	*ptr_stack_a;

	i = 0;
	ptr_stack_a = ps->stack_a;
	if (!ptr_stack_a)
		return ;
	ps->little = ptr_stack_a->content;
	while (ptr_stack_a)
	{
		if (ps->big <= ptr_stack_a->content)
		{
			ps->big = ptr_stack_a->content;
			ps->big_index = i;
		}
		if (ps->little >= ptr_stack_a->content)
		{
			ps->little = ptr_stack_a->content;
			ps->little_index = i;
		}
		ptr_stack_a = ptr_stack_a->next;
		i++;
	}
	return ;
}

void	ft_sa(t_ps *ps)
{
	t_stack_a *ptr_stack_a;

	ptr_stack_a = ps->stack_a;
	ps->stock = ptr_stack_a->content;
	if (ptr_stack_a->next)
	{
		ptr_stack_a->content = ptr_stack_a->next->content;
		ptr_stack_a = ptr_stack_a->next;
		ptr_stack_a->content = ps->stock;
	}
	printf("sa\n");
}

void	ft_ra(t_ps *ps)
{
	t_stack_a *ptr_stack_a;

	ptr_stack_a = ps->stack_a;
	ps->stock = ptr_stack_a->content;
	while (ptr_stack_a->next)
	{
		ptr_stack_a->content = ptr_stack_a->next->content;
		ptr_stack_a = ptr_stack_a->next;
	}
	ptr_stack_a->content = ps->stock;
	printf("ra\n");
}

void	ft_rb(t_ps *ps)
{
	t_stack_a *ptr_stack_b;

	ptr_stack_b = ps->stack_b;
	ps->stock = ptr_stack_b->content;
	while (ptr_stack_b->next)
	{
		ptr_stack_b->content = ptr_stack_b->next->content;
		ptr_stack_b = ptr_stack_b->next;
	}
	ptr_stack_b->content = ps->stock;
	printf("rb\n");
}

void	ft_rra(t_ps *ps)
{
	t_stack_a *ptr_stack_a;
	t_stack_a *first;

	first = ps->stack_a;
	ptr_stack_a = ps->stack_a;
	while (ptr_stack_a->next->next)
	{
		ps->stock = ptr_stack_a->next->content;
		ptr_stack_a->next->content = ptr_stack_a->content;
		ptr_stack_a->content = ps->stock;
		ptr_stack_a = ptr_stack_a->next;
	}
	ps->stock = first->content;
	first->content = ptr_stack_a->next->content;
	ptr_stack_a->next->content = ps->stock;
	printf("rra\n");
}

void	ft_rrb(t_ps *ps)
{
	t_stack_a *ptr_stack_b;
	t_stack_a *first;

	first = ps->stack_b;
	ptr_stack_b = ps->stack_b;
	while (ptr_stack_b->next->next)
	{
		ps->stock = ptr_stack_b->next->content;
		ptr_stack_b->next->content = ptr_stack_b->content;
		ptr_stack_b->content = ps->stock;
		ptr_stack_b = ptr_stack_b->next;
	}
	ps->stock = first->content;
	first->content = ptr_stack_b->next->content;
	ptr_stack_b->next->content = ps->stock;
	printf("rrb\n");
}

void	ft_three(t_ps *ps)
{
	if (!ft_sorted(ps))
	{
		if (ps->big_index == 2 && ps->little_index == 1)
			ft_sa(ps);
		else if (ps->big_index == 0 && ps->little_index == 1)
			ft_ra(ps);
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

t_stack_a	*del_one(t_stack_a *lst)
{
	t_stack_a *ptr_lst;
	if (!lst)
		return (NULL);
	ptr_lst = lst;
	lst = lst->next;
	free(ptr_lst);
	return (lst);
}

void	ft_pb(t_ps *ps)
{
	ft_stackadd_front(&ps->stack_b, ft_stacknew(ps->stack_a->content));
	ps->stack_a = del_one(ps->stack_a);
	printf("pb\n");
}


void ft_pa(t_ps *ps)
{
	if (!ps->stack_b)
		ps->stack_a = ft_stacknew((ps->stack_b->content));
	ft_stackadd_front(&ps->stack_a, ft_stacknew(ps->stack_b->content));
	printf("pa\n");
}

void three_left(t_ps *ps)
{
	if (ps->size == 3)
	{
		ft_three(ps);
		while (ps->stack_b)
		{
			ft_pa(ps);
			ps->stack_b = ps->stack_b->next;
		}
	}
}

void up_and_down_algo(t_ps *ps)
{
	double divid;

	while (ps->little_index != 0)
	{
		find_little_big(ps);
		if (ps->little_index == 1)
			ft_sa(ps);
		else
		{
			divid = ps->little_index;
			if (divid / 2 >= 0.5)
				ft_rra(ps);
			else
				ft_ra(ps);
		}
		find_little_big(ps);
		if (ft_sorted(ps))
			return;
	}
}
void	ft_under_twenty(t_ps *ps)
{
	if (!ft_sorted(ps))
	{
		while (ps->stack_a)
		{
			three_left(ps);
			up_and_down_algo(ps);
			if (ps->little_index == 0)
			{
				ft_pb(ps);
				ps->size--;
				find_little_big(ps);
			}
		}
	}
}

int			ft_find_in_list(int content, int *lst, int size)
{
	int i;

	i = -1;
	//printf("size=%d\n", size);
	while (++i < size)
	{
		//printf("content==%d\n", content);
		//printf("lst[i]==%d\n", lst[i]);
		//printf("i=%d\n", i);
		if (content == lst[i])
			return (1);
	}
	return (0);
}

int ft_find_index_back(t_ps *ps, int j)
{
	int i;
	int max;

	i = 0;
	max = (ft_stacksize(ps->stack_a) - 1);
	ps->ptr_stack_a = ps->stack_a;
	while (max >= 0)
	{
		ps->ptr_stack_a = ps->stack_a;
		while (i++ < max)
			ps->ptr_stack_a = ps->ptr_stack_a->next;
		//printf("{%d}\n", ps->ptr_stack_a->content);
		if (ft_find_in_list(ps->ptr_stack_a->content, ps->tab_lst[j] , ps->lst_size[j]))
		{
			//printf("FIND\n");
			ps->hold_second = i;
			return (1);
		}
		i = 0;
		max--;
	}
	return (0);
}

int  ft_find_index_top(t_ps *ps, int j)
{
	int index;

	index = 0;
	ps->ptr_stack_a = ps->stack_a;
	while (ps->ptr_stack_a)
	{
		if (ft_find_in_list(ps->ptr_stack_a->content, ps->tab_lst[j] , ps->lst_size[j]))
		{
			//printf("FIND\n");
			ps->hold_first = index;
			return (1);
		}
		//printf("i ===========] %d\n", index);
		index++;
		ps->ptr_stack_a = ps->ptr_stack_a->next;
	}
	return (0);
}

int find_index(t_ps *ps)
{
	int stock;
	int index;

	index = 0;
	stock = 0;
	ps->ptr_stack_b = ps->stack_b;
	ps->ptr_stack_a = ps->stack_a;
	while (index < ps->b_size && ps->ptr_stack_b)
	{
		//printf("!\n");
		if (ps->ptr_stack_b->content > stock)
		{
			if (ps->ptr_stack_b->content - stock > ps->ptr_stack_b->content - ps->ptr_stack_a->content)
				stock = ps->ptr_stack_b->content;
		}
		ps->ptr_stack_b = ps->ptr_stack_b->next;
		index++;
	}
	printf("stock{%d}\n", stock);
	printf("push avec{%d}\n", ps->ptr_stack_a->content);
	//printf("%d\n", ps->b_size);
	index--;
	if (stock == ps->stack_b->content)
		index = 0;
	//printf("index[%d]\n", index);
	return(index);
}

void insert_before(t_ps *ps, int i)
{
	return;
}

void insert_after(t_ps *ps, int i)
{
	t_stack_a *new;
	double index;

	i = 0;
	index = 0;
	ps->ptr_stack_b = ps->stack_b;
	ps->ptr_stack_a = ps->stack_a;
	if (!ps->ptr_stack_b)
		return;
	while (ps->ptr_stack_b && ps->ptr_stack_b->content < ps->ptr_stack_a->content && index <= ps->b_size)
	{
		ps->ptr_stack_b = ps->ptr_stack_b->next;
		index++;
	}
	index = find_index(ps);
	index--;
	printf("i{%f}\n", index);
	// if (ps->b_size - index <= index)
	// {
	// 	index = ps->b_size - index;
	// 	while (index-- > 0)
	// 		ft_rrb(ps);
	// }
	while (index-- > 0)
		ft_rb(ps);
}

void ft_insert(t_ps *ps, int i, int instruction)
{
	if (!ps->ptr_stack_b)
		ps->ptr_stack_b = ft_stacknew(ps->stack_a->content);
	insert_after(ps, i);
	ps->b_size++;
	if(ps->b_size == 6)
		exit(0);
}

void	ft_big(t_ps *ps)
{
	int i;
	int itab;
	int gototop;
	int up;

	while (!ft_sorted(ps))
	{
		itab = 0;
		while (ps->lst_size[itab] == 0 && itab <= ps->nbr_list - 1)
			itab++;
		up = 1;
		if (!ft_find_index_top(ps, itab))
			return ;
		if (!ft_find_index_back(ps, itab))
			return ;
		//printf("!%d!\n", ps->hold_first);
		//printf("!%d!\n", ps->hold_second);
		//printf("<%d>", ft_stacksize(ps->stack_a) - ps->hold_second + 1);
		if ((ps->hold_first < (ft_stacksize(ps->stack_a)) - ps->hold_second + 1))
		{
			up = 0;
			gototop = ps->hold_first;
		}
		else
		{
			gototop = ps->hold_second;
		}
		ps->little_index = gototop;
		three_left(ps);
		while (ps->little_index != 0)
		{
			if (ft_sorted(ps))
				return;
			//find_little_big(ps);
			if (ps->little_index == 1)
				ft_sa(ps);
			else
			{
				if (up == 1)
					ft_rra(ps);
				else
					ft_ra(ps);
			}
			ps->lst_size[itab]--;
			break;
		}
		printf("------------------------------------------\n");
		ft_insert(ps, ps->little_index, 0);
		ft_pb(ps);
		ft_print_stack(ps->stack_b);
	}
}
