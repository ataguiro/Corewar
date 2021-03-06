/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:35:57 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/06/06 14:44:41 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_decode	*l_valid_or(t_process *proc)
{
	unsigned char	ocp;
	t_decode		*args;

	ocp = g_env.map.str[(proc->pc + 1) % MEM_SIZE];
	args = vm_decode_octet(ocp, false);
	proc->pc = (proc->pc + args->param1 + args->param2 +
							args->param3 + 2) % MEM_SIZE;
	nc_move_cursor(proc->pc, g_env.from);
	if ((ocp & P3_MSK) != P3_REG)
		return (NULL);
	return (args);
}

static bool		l_or_args(t_process *proc, t_decode *args)
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

void			in_or(t_process *proc)
{
	t_decode		*args;
	size_t			curs;

	g_env.from = proc->pc;
	curs = (proc->pc + 2) % MEM_SIZE;
	if (!(args = l_valid_or(proc)))
		return ;
	vm_get_arg(args, &curs);
	if (!l_or_args(proc, args))
		return ;
	if (args->param1 == IND_SIZE)
		args->arg1 = vm_get_param_val(g_env.from + (args->arg1 % IDX_MOD), 4);
	if (args->param2 == IND_SIZE)
		args->arg2 = vm_get_param_val(g_env.from + (args->arg2 % IDX_MOD), 4);
	proc->reg[args->arg3] = args->arg1 | args->arg2;
}
