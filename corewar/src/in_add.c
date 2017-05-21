/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:35:34 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/20 23:01:04 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_decode *l_valid_add(t_process *proc)
{
	unsigned char 	ocp;
	t_decode 		*args;

	ocp = g_env.map.str[(proc->pc + 1) % MEM_SIZE];
	args = vm_decode_octet(ocp, false);
	proc->pc = (proc->pc + args->param1 + args->param2 +
							args->param3 + 2) % MEM_SIZE;
	if ((ocp & p1_IND) != P1_REG || (ocp & P2_IND) != P2_REG ||
		(ocp & P3_IND) != P3_REG)
		return (NULL);
	return (args);
}

static bool l_add_args(t_process *proc, t_decode *args)
{
	if (args->arg1 < 1 || args->arg1 > 16)
		return (false);
	if (args->arg2 < 1 || args->arg2 > 16)
		return (false);
	if (args->arg3 < 1 || args->arg3 > 16)
		return (false);
	return (true);
}

void in_add(t_process *proc)
{
	t_decode *args;
	size_t	curs;

	curs = (proc->pc + 2) % MEM_SIZE;
	if (!(args = l_valid_add(proc)))
		return ;
	vm_get_arg(args, &curs, false);
	if (!l_add_args(proc, args))
		return ;
	process->reg[args->arg3] = process->reg[args->arg1] + process->reg[args->arg2];
	proc->carry = proc->reg[args->arg3] ? false : true;
}

// void in_add(t_process *process)
// {
// 	t_decode *args;
// 	size_t	curs;

// 	curs = (process->pc + 1) % MEM_SIZE;
// 	args = vm_decode_octet(g_env.map.str[curs++], false);
// 	vm_get_arg(args, &curs, false);
// 	if ((args->arg1 > 0 && args->arg1 < 17) &&
// 		(args->arg2 > 0 && args->arg2 < 17) &&
// 		(args->arg3 > 0 && args->arg3 < 17))
// 	{
// 		process->reg[args->arg3] = process->reg[args->arg1] + process->reg[args->arg2];
// 		if (!process->reg[args->arg3])
// 			process->carry = 1;
// 	}
// 	process->pc = curs % MEM_SIZE;
// }