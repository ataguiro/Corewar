/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:37:08 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/31 17:23:19 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	in_lfork(t_process *process)
{
	size_t		curs;
	int			value;

	g_env.from = process->pc;
	curs = (process->pc + 1) % MEM_SIZE;
	value = (short)vm_get_param_val(curs, 2);
	vm_lst_add_cpy(&process);
	process->pc = (process->pc + 3) % MEM_SIZE;
	g_env.process->pc = (g_env.process->pc + value) % MEM_SIZE;
	g_env.process->instr = g_env.map.str[g_env.process->pc];
	g_env.map.nb_process++;
	if (g_env.process->instr > 0 && g_env.process->instr < 17)
		g_env.process->cycles_cd = g_env.cycles_size[g_env.process->instr];
	else
		g_env.process->cycles_cd = 1;
	++g_env.map.cursor[process->pc];
	nc_move_cursor(g_env.process->pc, process->pc);
	nc_move_cursor(process->pc, g_env.from);
}
