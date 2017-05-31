/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:36:49 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/31 17:19:55 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_decode	*l_valid_lld(t_process *proc)
{
	unsigned char 	ocp;
	t_decode 		*args;

	ocp = g_env.map.str[(proc->pc + 1) % MEM_SIZE];
	args = vm_decode_octet(ocp, false);
	proc->pc = (proc->pc + args->param1 + args->param2 + 2) % MEM_SIZE;
	nc_move_cursor(proc->pc, g_env.from);	
	if ((ocp & P1_MSK) == P1_REG || (ocp & P2_MSK) != P2_REG)
		return (NULL);
	return (args);
}

void			in_lld(t_process *proc)
{
	t_decode	*args;
	size_t		curs;

	g_env.from = proc->pc;
	curs = (proc->pc + 2) % MEM_SIZE;
	if (!(args = l_valid_lld(proc)))
		return ;
	vm_get_arg(args, &curs);
	if (args->param1 == IND_SIZE)
		args->arg1 = vm_get_param_val(g_env.from + args->arg1, 4);
	if (args->arg2 > 0 && args->arg2 < 17)
		proc->reg[args->arg2] = args->arg1;
	proc->carry = proc->reg[args->arg2] ? false : true;
	nc_move_cursor(proc->pc, g_env.from);
}
