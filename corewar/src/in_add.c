/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:35:34 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/31 17:20:58 by folkowic         ###   ########.fr       */
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
	nc_move_cursor(proc->pc, g_env.from);	
	if ((ocp & P1_IND) != P1_REG || (ocp & P2_IND) != P2_REG ||
		(ocp & P3_IND) != P3_REG)
		return (NULL);
	return (args);
}

static bool l_add_args(t_process *proc, t_decode *args)
{
	if (args->arg1 < 1 || args->arg1 > 16)
		return (false);
	args->arg1 = proc->reg[args->arg1];
	if (args->arg2 < 1 || args->arg2 > 16)
		return (false);
	args->arg2 = proc->reg[args->arg2];
	if (args->arg3 < 1 || args->arg3 > 16)
		return (false);
	return (true);
}

void in_add(t_process *proc)
{
	t_decode *args;
	size_t	curs;

	g_env.from = proc->pc;
	curs = (proc->pc + 2) % MEM_SIZE;
	if (!(args = l_valid_add(proc)))
		return ;
	vm_get_arg(args, &curs);
	if (!l_add_args(proc, args))
		return ;
	proc->reg[args->arg3] = args->arg1 + args->arg2;
	proc->carry = proc->reg[args->arg3] ? false : true;
}
