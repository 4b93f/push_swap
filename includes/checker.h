/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:50:16 by chly-huc          #+#    #+#             */
/*   Updated: 2021/04/29 17:31:18 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/libft.h"
# include "push_swap.h"
# include "../get_next_line/get_next_line.h"

void		ft_checker_sa(t_ps *ps);
void		ft_checker_ra(t_ps *ps);
void		ft_checker_pa(t_ps *ps);
void		ft_checker_rb(t_ps *ps);
void		ft_checker_pb(t_ps *ps);
void		ft_checker_rrb(t_ps *ps);
void		ft_checker_rra(t_ps *ps);

#endif