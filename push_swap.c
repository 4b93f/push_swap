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
    {
        ft_stackadd_back(&ps->stack_a, ft_stacknew(ft_atoi(argv[i])));
        //ft_stackadd_back(&ps->stack_b, ft_stacknew(0));
    }
}

int main(int argc, char **argv)
{
    t_ps *ps;

    if (argc <= 3)
        ft_error(LESS_ARG);
    ps = ft_malloc_ps();
    ps->size = argc - 1;
    ft_create_stack(ps, argv);
	ft_print_stack(ps->stack_a);
	//printf("-------------------------\n");
	find_little_big(ps);
    if (argc == 4)
        ft_three(ps);
    if (argc > 4 && argc < 51)
        ft_under_fifty(ps);
    if (ft_sorted(ps))
    {
        printf("TRIED\n");
		ft_print_stack(ps->stack_b);
		ft_print_stack(ps->stack_a);
        exit(0);
    }
    else
    {
        printf("NOT TRIED\n");
		ft_print_stack(ps->stack_a);
        exit(0);
    }
    return 0;
}