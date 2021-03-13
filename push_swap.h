/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shyrno <shyrno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 21:03:40 by shyrno            #+#    #+#             */
/*   Updated: 2021/03/13 02:11:46 by shyrno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

typedef struct  s_ps
{
    int     *pile_a;
    int     *pile_b;
    int     size;
    int     actual;
    int     little;
    int     big;
    int     i;
}               t_ps;

typedef struct  s_lst
{
    int     content;
    void *next;
}               t_stack_a;



t_ps	*ft_malloc_ps(void);
void    ft_three(t_ps *ps);
int     ft_sorted(t_ps *ps);
void    ft_under_fifty(t_ps *ps);