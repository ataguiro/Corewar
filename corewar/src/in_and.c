/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:35:47 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/20 16:21:36 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	in_and(t_process *process)
{
	t_decode *args;
	size_t	curs;

	curs = (process->pc + 1) % MEM_SIZE;
	args = vm_decode_octet(g_env.map.str[curs++]);
	vm_get_arg(args, &curs);
	if (args->param1 == 1 && args->arg1 > 0 && args->arg1 < 17)
		args->arg1 = process->reg[args->arg1];
	else if (args->param1 == 2)
	{
		args->arg1 = (short)args->arg1;
		args->arg1 = vm_get_param_val(process->pc + (args->arg1 % IDX_MOD), 4);
	}
	if (args->param2 == 1 && args->arg2 > 0 && args->arg2 < 17)
		args->arg2 = process->reg[args->arg2];
	else if (args->param2 == 2)
	{
		args->arg2 = (short)args->arg2;
		args->arg2 = vm_get_param_val(process->pc + (args->arg2 % IDX_MOD), 4);
	}
	if (args->param1 && args->param2 && args->param3)
	{
		if (args->param3 == 1 && args->arg3 > 0 && args->arg3 < 17)
		{
			process->reg[args->arg3] = args->arg1 & args->arg2;
			process->carry = process->reg[args->arg3] ? false : true;
		}
		process->pc = curs % MEM_SIZE;
	}
	else
	{
		process->pc = (process->pc + 2) % MEM_SIZE;
		process->carry = false;
	}
}