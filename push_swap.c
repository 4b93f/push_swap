/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:17:05 by marvin            #+#    #+#             */
/*   Updated: 2021/03/11 20:17:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void ft_error(int ret)
{
    static char *error[] = {
    "Error with argument\n"
    };
    printf("%s", error[ret]);
    exit(0);
}

t_stack_a *ft_create_stack(t_ps *ps, char **argv)
{
	t_stack_a *list;
    int i;

	i = 1;
    list = ft_stacknew(ft_atoi(argv[i]));    
    while (argv[++i])
        ft_stackadd_back(&list, ft_stacknew(ft_atoi(argv[i])));
	return (list);
}

int find_duplicate(char **argv)
{
	int i;
	int j;
	int len;
	char *stock;

	i = 0;
	j = 0;
	len = 0;
	while(argv[++i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
	}
	return (1);
}

void	sort_argv(t_ps *ps, char **argv)
{
	int i;
	int j;
	char *tmp;

	tmp = NULL;
	
	i = 0;
	while (argv[++i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) > ft_atoi(argv[j]))
			{
				tmp = argv[i];
				argv[i] = argv[j];
				argv[j] = tmp;
			}
			j++;
		}
	}
}

void ft_scale(t_ps *ps)
{
	if (ps->size < 100)
		ps->nbr_list = 4;
	if (ps->size >= 100 && ps->size < 500)
		ps->nbr_list = 6;
	if (ps->size >= 500 & ps->size < 1000)
		ps->nbr_list = 12;
	if (ps->size >= 1000)
		ps->nbr_list = 18;
}

int *fill_tab_lst(t_ps *ps, int len, int size)
{
	int i;
	int *tab_lst;

	i = 0;
	tab_lst = malloc(sizeof(int) * (len + 1));
	//printf("<%d>", len);
	if (!tab_lst)
		return(NULL);
	while (i < len || !ps->sorted_lst)
	{
		if (!ps->sorted_lst->next && ++i)
			break;
		tab_lst[i] = ps->sorted_lst->content;
		ps->sorted_lst = ps->sorted_lst->next;
		i++;
	}
	ps->lst_size[size] = i;
	printf("[%d]\n", i);
	return (tab_lst);
}

void ft_create_tablist(t_ps *ps)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = ps->size / ps->nbr_list;

	if (ps->size % ps->nbr_list != 0)
		len++;
	ps->tab_lst = malloc(sizeof(int*) * ps->nbr_list);
	ps->lst_size = malloc(sizeof(int) * ps->nbr_list);
	while (i < ps->nbr_list)
	{
		ps->tab_lst[i] = fill_tab_lst(ps, len, i);
		i++;
	}

}

int main(int argc, char **argv)
{
    t_ps *ps;

    ps = ft_malloc_ps();
	ps->stack_a = ft_create_stack(ps, argv);
	sort_argv(ps, argv);
	ps->sorted_lst = ft_create_stack(ps, argv);
    ps->size = argc - 1;
    if (argc <= 3)
        ft_error(LESS_ARG);
	if (argc < 4)
		return (0);
	if (!find_duplicate(argv))
	{
		printf("Error\nFin Duplicate.\n");
		exit(0);
	}
	find_little_big(ps);
    if (argc == 4)
        ft_three(ps);
	ft_scale(ps);
	if (ps->nbr_list > 0)
		ft_create_tablist(ps);
    if (argc > 4 && argc < 50)
	{
        ft_under_twenty(ps);
	}
	else
	{
		ft_big(ps);
	}
    if (ft_sorted(ps))
    {
        printf("TRIED\n");
		//ft_print_stack(ps->stack_b);
		//ft_print_stack(ps->stack_a);
		ft_stackclear(&ps->stack_a, free);
        exit(0);
		
    }
    else
    {
        //printf("NOT TRIED\n");
		//ft_print_stack(ps->stack_a);
		ft_stackclear(&ps->stack_a, free);
        exit(0);
    }
    return 0;
}
