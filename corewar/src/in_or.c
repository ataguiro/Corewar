/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:35:57 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/21 19:19:55 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_decode *l_valid_or(t_process *proc)
{
	unsigned char 	ocp;
	t_decode 		*args;

	ocp = g_env.map.str[(proc->pc + 1) % MEM_SIZE];
	args = vm_decode_octet(ocp, false);
	proc->pc = (proc->pc + args->param1 + args->param2 +
							args->param3 + 2) % MEM_SIZE;
	if ((ocp & P3_MSK) != P3_REG)
		return (NULL);
	return (args);
}

static bool l_or_args(t_process *proc, t_decode *args)
{
	if (args->param1 == REG_SIZE)
	{
		if (args->arg1 < 1 || args->arg1 > 16)
			return (false);
		args->arg1 = proc->reg[args->arg1];
	}
	if (args->param2 == REG_SIZE)
	{
		if (args->arg2 < 1 || args->arg2 > 16)
			return (false);
		args->arg2 = proc->reg[args->arg2];
	}
	if (args->arg3 < 1 || args->arg3 > 16)
		return (false);
	return (true);
}

void	in_or(t_process *proc)
{
	t_decode *args;
	size_t	curs;
	size_t	from;

	from = proc->pc;
	curs = (proc->pc + 2) % MEM_SIZE;
	if (!(args = l_valid_or(proc)))
		return ;
	vm_get_arg(args, &curs, false);
	if (!l_or_args(proc, args))
		return ;
	if (args->param1 == IND_SIZE)
		args->arg1 = vm_get_param_val(from + (args->arg1 % IDX_MOD), 4);
	if (args->param2 == IND_SIZE)
		args->arg2 = vm_get_param_val(from + (args->arg2 % IDX_MOD), 4);
	proc->reg[args->arg3] = args->arg1 | args->arg2;
	// proc->carry = proc->reg[args->arg3] ? false : true;
}

// void	in_or(t_process *process)
// {
// 	t_decode *args;
// 	size_t	curs;
//
// 	curs = (process->pc + 1) % MEM_SIZE;
// 	args = vm_decode_octet(g_env.map.str[curs++], false);
// 	vm_get_arg(args, &curs, false);
// 	if (args->param1 == 1 && args->arg1 > 0 && args->arg1 < 17)
// 		args->arg1 = process->reg[args->arg1];
// 	else if (args->param1 == 2)
// 	{
// 		args->arg1 = (short)args->arg1;
// 		args->arg1 = vm_get_param_val(process->pc + (args->arg1 % IDX_MOD), 4);
// 	}
// 	if (args->param2 == 1 && args->arg2 > 0 && args->arg2 < 17)
// 		args->arg2 = process->reg[args->arg2];
// 	else if (args->param2 == 2)
// 	{
// 		args->arg2 = (short)args->arg2;
// 		args->arg2 = vm_get_param_val(process->pc + (args->arg2 % IDX_MOD), 4);
// 	}
// 	if (args->param1 && args->param2 && args->param3)
// 	{
// 		if (args->param3 == 1 && args->arg3 > 0 && args->arg3 < 17)
// 		{
// 			process->reg[args->arg3] = args->arg1 | args->arg2;
// 			process->carry = process->reg[args->arg3] ? false : true;
// 		}
// 		process->pc = curs % MEM_SIZE;
// 	}
// 	else
// 	{
// 		process->pc = (process->pc + 2) % MEM_SIZE;
// 		process->carry = false;
// 	}
// }
