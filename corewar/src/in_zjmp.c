/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:36:14 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/31 17:20:41 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	in_zjmp(t_process *process)
{
	size_t	curs;
	int		value;

	g_env.from = process->pc;
	curs = (process->pc + 1) % MEM_SIZE;
	value = (short)vm_get_param_val(curs, 2);
	if (process->carry)
		process->pc = (process->pc + (value % IDX_MOD)) % MEM_SIZE;
	else
		process->pc = (process->pc + 3) % MEM_SIZE;
	nc_move_cursor(process->pc, g_env.from);
}
