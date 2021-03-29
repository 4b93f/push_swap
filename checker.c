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

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void ft_create_stack(t_ps *ps, char **argv)
{
    int i;

    i = 1;
    ps->stack_a = ft_stacknew(ft_atoi(argv[i]));
	ft_print_stack(ps->stack_a);
	printf("[%d]\n", ps->stack_a->content);
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

    ps = ft_malloc_ps();
    if (argc <= 3)
        ft_error(LESS_ARG);
    ps->size = argc - 1;
    ft_create_stack(ps, argv);
	int i;

	i = 0;
	while (get_next_line(0, &line))
	{
		printf("line=%s\n",line);
		if (!strcmp(line, "sa"))
			ft_sa(ps);
		if (!strcmp(line, "ra"))
			ft_ra(ps);
		if (!strcmp(line, "rra"))
			ft_rra(ps);
		if (!strcmp(line, "pb"))
			ft_pb(ps);
		if (!strcmp(line, "pa"))
			ft_pa_checker(ps);
		free(line);
	}
	//printf("%d\n", i);
    if (ft_sorted(ps))
        printf("OK\n");
    return (0);
}