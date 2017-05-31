/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_call_instruct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 18:32:12 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/31 17:16:39 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_call_instruct(t_process *process)
{


	g_env.from = process->pc;
	if (process->instr > 0 && process->instr < 17)
	{
		g_env.instruction[process->instr](process);
		process->instr = 0;
	}
	else
	{
		process->pc = (process->pc + 1) % MEM_SIZE;
		nc_move_cursor(process->pc, g_env.from);
	}
}
