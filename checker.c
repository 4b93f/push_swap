/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:36:10 by marvin            #+#    #+#             */
/*   Updated: 2021/03/11 20:36:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "checker.h"

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
	char *line;

    if (argc <= 3)
        ft_error(LESS_ARG);
    ps = ft_malloc_ps();
    ps->size = argc - 1;
    ft_create_stack(ps, argv);
	while (get_next_line(0, &line))
	{
		if (strcmp(line, "sa"))
			ft_sa(ps);
		if (strcmp(line, "ra"))
			ft_ra(ps);
		if (strcmp(line, "rra"))
			ft_rra(ps);
		if (strcmp(line, "pb"))
			ft_pb(ps);
		free(line);
	}
    if (ft_sorted(ps))
        printf("OK\n");
    return (0);
}