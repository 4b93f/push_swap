/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shyrno <shyrno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 22:40:14 by shyrno            #+#    #+#             */
/*   Updated: 2021/03/12 19:40:24 by shyrno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_sorted(t_ps *ps)
{
    int i;

    i = -1;
    while (++i <= ps->size)
    {
        while(ps->pile_a[i + 1] && i <= ps->size)
        {
            if (ps->pile_a[i] < ps->pile_a[i + 1])
                i++;
            else
                return (0);
        }
        return (1);
    }
    return (1);
}

void ft_duplicate()
{
    
}

void find_little_big(t_ps *ps)
{
    int i;
    
    i = -1;
    ps->big = ps->pile_a[i + 1];
    ps->little = ps->pile_a[i + 1];
    while (++i < ps->size)
    {
        if (ps->big < ps->pile_a[i])
            ps->big = ps->pile_a[i];
        if (ps->little > ps->pile_a[i])
            ps->little = ps->pile_a[i];  
    }
    return ;
}

void ft_sa(t_ps *ps, int first, int second)
{
    int tmp;

    tmp = ps->pile_a[first];
    ps->pile_a[first] = ps->pile_a[second];
    ps->pile_a[second] = tmp;
}

void ft_ra(t_ps *ps)
{
    int tmp;
    int i;

    i = -1;
    tmp = ps->pile_a[i + 1];
    ps->pile_a[i + 1] = ps->pile_a[ps->size];
    ps->pile_a[ps->size] = tmp;
    while(++i < ps->size)
    {
        tmp = ps->pile_a[i];
        ps->pile_a[i] = ps->pile_a[i + 1];
        ps->pile_a[i + 1] = tmp;
    }
}


void ft_rra(t_ps *ps)
{
    //printf("!!!! == %d %d %d\n", ps->pile_a[0], ps->pile_a[1], ps->pile_a[2]);
    int tmp;
    int i;

    i = 0;
    tmp = ps->pile_a[i];
    ps->pile_a[i] = ps->pile_a[ps->size - 1];
    ps->pile_a[ps->size - 1] = tmp;
    //printf("!!!! == %d %d %d\n", ps->pile_a[0], ps->pile_a[1], ps->pile_a[2]);
    while(++i < ps->size - 1)
    {
        //printf("i = %d\n", i);
        tmp = ps->pile_a[i];
        ps->pile_a[i] = ps->pile_a[i + 1];
        ps->pile_a[i + 1] = tmp;
    }
}


void ft_swap(t_ps *ps, int first, int second)
{
    int i;

    i = 0;
    find_little_big(ps);
    //printf("big = %d little = %d\n", ps->big, ps->little);
    if (!ft_sorted(ps))
    {
        if (ps->pile_a[2] == ps->big && ps->pile_a[1] == ps->little)
            ft_sa(ps, 0, 1);
        else if (ps->pile_a[0] == ps->big && ps->pile_a[1] == ps->little) 
            ft_ra(ps);
        else if (ps->pile_a[1] == ps->big && ps->pile_a[0] == ps->little)
        {
            ft_sa(ps, 0, 1);
            ft_ra(ps);
        }
        else if (ps->pile_a[1] == ps->big && ps->pile_a[2] == ps->little)
            ft_rra(ps);
        else if (ps->pile_a[0] == ps->big && ps->pile_a[2] == ps->little)
        {
            ft_sa(ps, 0, 1);
            ft_rra(ps);
        }
    }
    return ;
}

void ft_three(t_ps *ps)
{
    int i;
    int j;
    
    j = 0;
    i = 0;
    while (j < ps->size)
    {
        ps->actual = ps->pile_a[j];
        while (ps->pile_a[i] && ps->actual < ps->pile_a[++i])
            ;
        if (i < ps->size)
            ft_swap(ps, j, i);        
        j += 1;
        i = j;
    }
    return ;
}

void ft_under_fifty(t_ps *ps)
{
    
    find_little_big(ps);
    
}
