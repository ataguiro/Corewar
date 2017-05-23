/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:36:38 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/23 12:45:48 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void in_fork(t_process *process)
{
	size_t		curs;
	int			value;

	curs = (process->pc + 1) % MEM_SIZE;
	value = (short)vm_get_param_val(curs, 2) % IDX_MOD;
	vm_lst_add_cpy(&process);
	process->pc = (process->pc + 3) % MEM_SIZE;
	g_env.process->pc = (g_env.process->pc + value) % MEM_SIZE;
	g_env.process->instr = g_env.map.str[g_env.process->pc];
	++g_env.map.nb_process;
	if (g_env.process->instr > 0 && g_env.process->instr < 17)
		g_env.process->cycles_cd = g_env.cycles_size[g_env.process->instr];
	else
		g_env.process->cycles_cd = 1;
}
