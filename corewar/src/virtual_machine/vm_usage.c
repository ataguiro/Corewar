/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:35:46 by folkowic          #+#    #+#             */
/*   Updated: 2017/06/06 15:05:25 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_usage(void)
{
	ft_printf("Usage:	[-dump nbr_cycles] [[-n number] champion1.cor] ...\n");
	ft_printf("			-s -> show with ncurse\n");
	exit(EXIT_FAILURE);
}
