/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_call_instruct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 18:32:12 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/26 17:12:20 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_call_instruct(t_process *process)
{
	if (process->instr > 0 && process->instr < 17)
	{
		g_env.instruction[process->instr](process);
		process->instr = 0;
	}
	else
		process->pc = (process->pc + 1) % MEM_SIZE;
}
