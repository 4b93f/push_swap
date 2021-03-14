/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chly-huc <chly-huc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:34:27 by chly-huc          #+#    #+#             */
/*   Updated: 2021/03/13 16:34:59 by chly-huc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab && tab[++i])
		ft_putstr_fd(tab[i], 1);
}
