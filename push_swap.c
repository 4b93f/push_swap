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
    return ;
}

void ft_stack_to_pile_a(int argc, char **argv, t_ps *ps)
{
    int i;
    int j;
    
    i = 0;
    
    if (!(ps->pile_a = malloc(sizeof(int) * i + 1)))
        return ;
    i = -1;
    j = 0;
    while (argv[++j])
        ps->pile_a[++i] = ft_atoi(argv[j]);
    ps->pile_a[++i] = '\0';
    return ;
}

t_stack_a *create_lst(void *content)
{
    t_stack_a *new;

    new = malloc(sizeof(t_stack_a));
    if (!new)
        return (NULL);
    new->content = ft_atoi(content);
    new->next = NULL;
    return (new);
}

void ft_init_lst(t_stack_a **lst, t_ps *ps, char **argv)
{
    int i;

    i = 0;
    *lst = create_lst(argv[++i]);
}

void ft_print_list(t_stack_a *lst)
{
    printf("!\n");
    while (lst)
    {
        printf("%d\n", lst->content);
        lst = lst->next;
    }
}

int main(int argc, char **argv)
{
    t_ps *ps;
    t_stack_a *lst;
    
    lst = NULL;
    ps = ft_malloc_ps();
    ps->size = argc - 1;
    ft_init_lst(&lst, ps, argv);
    ft_add
    ft_print_list(lst);
    return (0);
    if (argc < 1)
        ft_error(0);
    ft_stack_to_pile_a(argc, argv, ps);
    if (argc == 4)
    {
        ft_three(ps);
        printf("%d %d %d\n", ps->pile_a[0], ps->pile_a[1], ps->pile_a[2]);
    }
    if (argc > 4  && argc < 51)
        ft_under_fifty(ps);
    if (ft_sorted(ps))
    {
        printf("TRIED\n");
        exit(0);
    }
    else
    {
        printf("NOT TRIED\n");
        exit(0);
    }
    return 0;
}