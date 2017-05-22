/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_show_reg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 20:48:02 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/22 15:05:16 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	db_show_reg(t_process *process)
{
	size_t	i;

	ft_printf("nb live %hhd\n", process->is_live);
	ft_printf("pc %zu\n", process->pc);
	ft_printf("carry %zu\n", process->carry);
	ft_printf("cycles_cd %zu\n", process->cycles_cd);
	i = 0;
	while (++i <= R16)
		ft_printf("reg[%zu] = %x\n", i, process->reg[i]);
}
