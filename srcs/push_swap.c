/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:17:05 by marvin            #+#    #+#             */
/*   Updated: 2021/04/22 21:11:48 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_argv(t_ps *ps, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

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
	ps->size = i;
}

static void	ft_start(t_ps *ps, int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	find_little_big(ps);
	if (argc <= 4)
		ft_three(ps);
	if (ft_sorted(ps))
		ft_exit(0);
	if (ps->nbr_list > 0)
		ft_create_tablist(ps);
	ps->ptr_stack_a = ps->stack_a;
	if (argc > 4 && argc < 50)
		ft_under_fifty(ps);
	else
		ft_big(ps, i, j);
	if (ft_sorted(ps))
		ft_exit(0);
}

int	main(int argc, char **argv)
{
	t_ps	*ps;

	ps = ft_malloc_ps();
	if (!ps)
		ft_error(MALLOC_ERROR, ps);
	handle_error(ps, argc, argv);
	ps->stack_a = ft_create_stack(ps, argv);
	sort_argv(ps, argv);
	ps->sorted_lst = ft_create_stack(ps, argv);
	ft_scale(ps);
	ft_start(ps, argc, argv);
	return (0);
}
