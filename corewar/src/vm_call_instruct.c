/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_call_instruct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 18:32:12 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/20 22:05:42 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void 	vm_call_instruct(t_process *process)
{
	//appelle la fonction suivant l' index et l' opcode sur lequel il se trouve
//	if (g_env.map.str[process->pc] > 0 && g_env.map.str[process->pc] < 17)
//	{
	if (process->instr > 0 && process->instr < 17)
	{
		// ft_printf("=======target %x==========\n", process->instr);
		g_env.instruction[process->instr](process);
//		g_env.instruction[g_env.map.str[process->pc]](process);
		db_show_reg(process);
		if (!g_env.cmd & DUMP)
			db_show_map();
		process->instr = 0;
	}
	else
		process->pc = (process->pc + 1) % MEM_SIZE;
}
