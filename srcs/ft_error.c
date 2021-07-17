/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 20:28:47 by chly-huc          #+#    #+#             */
/*   Updated: 2021/07/16 13:08:57 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	handle_error(t_ps *ps, int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		exit(0);
	if (argc < 4)
	{
		while (argv[i + 1] && ft_atoi(argv[i]) < ft_atoi(argv[i + 1]))
			i++;
		if (i != argc - 1)
			printf("Error\n");
		exit(0);
	}
	if (!find_duplicate(argv, ps))
		exit(0);
}

void	ft_exit(t_ps *ps)
{
	if (ps)
	{
		if (ps->stack_a)
			ft_stackclear(&ps->stack_a, free);
		if (ps->stack_b)
			ft_stackclear(&ps->stack_b, free);
		if (ps->sorted_lst)
			ft_stackclear(&ps->sorted_lst, free);
		if (ps->tab_lst)
			ft_free_int_tab(ps->tab_lst);
		if (ps->lst_size)
			free(ps->lst_size);
		free(ps);
	}
	exit(0);
}

void	ft_error(int ret, t_ps *ps)
{
	static char	*error[] = {
		"Error with malloc.\n",
		"Error\n"
	};

	write(2, error[ret], ft_strlen(error[ret]));
	ft_exit(ps);
}
