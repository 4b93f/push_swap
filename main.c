/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:21:02 by chly-huc          #+#    #+#             */
/*   Updated: 2021/03/13 16:27:53 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int argc, char **argv)
{
	t_list *stack_a;

	stack_a = ft_lstnew(argv[1]);
	ft_lstadd_back(&stack_a, ft_lstnew(argv[2]));
	ft_print_list(stack_a);
}
