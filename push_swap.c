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

void ft_create_stack(t_ps *ps, char **argv)
{
    int i;

	i = 1;
    ps->stack_a = ft_stacknew(ft_atoi(argv[i]));    
    while (argv[++i])
        ft_stackadd_back(&ps->stack_a, ft_stacknew(ft_atoi(argv[i])));
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

int main(int argc, char **argv)
{
    t_ps *ps;

    ps = ft_malloc_ps();

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
	ft_create_stack(ps, argv);
	find_little_big(ps);
    if (argc == 4)
        ft_three(ps);
    if (argc > 4)
	{
        ft_under_twenty(ps);
	}
    if (ft_sorted(ps))
    {
        //printf("TRIED\n");
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
