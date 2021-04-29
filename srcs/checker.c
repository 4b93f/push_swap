/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:36:10 by marvin            #+#    #+#             */
/*   Updated: 2021/04/23 17:49:15 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	start(t_ps *ps, char *line)
{
	while (get_next_line(0, &line))
	{
		if (!ft_strcmp(line, "sa"))
			ft_checker_sa(ps);
		if (!ft_strcmp(line, "ra"))
			ft_checker_ra(ps);
		if (!ft_strcmp(line, "rra"))
			ft_checker_rra(ps);
		if (!ft_strcmp(line, "rrb"))
			ft_checker_rrb(ps);
		if (!ft_strcmp(line, "rb"))
			ft_checker_rb(ps);
		if (!ft_strcmp(line, "pb"))
			ft_checker_pb(ps);
		if (!ft_strcmp(line, "pa"))
			ft_checker_pa(ps);
		free(line);
	}
	free(line);
}

int	main(int argc, char **argv)
{
	int		i;
	t_ps	*ps;
	char	*line;

	i = 0;
	line = NULL;
	ps = ft_malloc_ps();
	handle_error(ps, argc, argv);
	find_duplicate(argv, ps);
	ps->size = argc - 1;
	ps->stack_a = ft_create_stack(ps, argv);
	start(ps, line);
	if (ft_sorted(ps))
		printf("OK\n");
	return (0);
}
