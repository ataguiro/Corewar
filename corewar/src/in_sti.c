/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:36:32 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/06/04 16:26:38 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_decode	*l_valid_sti(t_process *proc)
{
	unsigned char 	ocp;
	t_decode 		*args;

	ocp = g_env.map.str[(proc->pc + 1) % MEM_SIZE];
	args = vm_decode_octet(ocp, true);
	proc->pc = (proc->pc + args->param1 + args->param2 +
							args->param3 + 2) % MEM_SIZE;
	nc_move_cursor(proc->pc, g_env.from);
	if ((ocp & P1_MSK) != P1_REG || (ocp & P3_MSK) == P2_IND)
		return (NULL);
	return (args);
}

static bool		l_sti_args(t_process *proc, t_decode *args)
{
	if (args->arg1 < 1 || args->arg1 > 16)
		return (false);
	args->arg1 = proc->reg[args->arg1];
	if (args->param2 == REG_SIZE)
	{
		if (args->arg2 < 1 || args->arg2 > 16)
			return (false);
		args->arg2 = proc->reg[args->arg2];
	}
	if (args->param3 == REG_SIZE)
	{
		if (args->arg3 < 1 || args->arg3 > 16)
			return (false);
		args->arg3 = proc->reg[args->arg3];
	}
	return (true);
}

void			in_sti(t_process *proc)
{
	t_decode	*args;
	size_t		curs;

	g_env.from = proc->pc;
	curs = (proc->pc + 2) % MEM_SIZE;
	if (!(args = l_valid_sti(proc)))
		return ;
	vm_get_arg(args, &curs);
	if (!l_sti_args(proc, args))
		return ;
	if ((g_env.map.str[(g_env.from + 1) % MEM_SIZE] & P2_MSK) == P2_IND)
		args->arg2 = vm_get_param_val(g_env.from + (args->arg2 % IDX_MOD), 4);
	vm_replace_int(g_env.from + ((args->arg2 + args->arg3) % IDX_MOD), args->arg1);
	vm_color_area(g_env.from + ((args->arg2 + args->arg3) % IDX_MOD), 4,
						proc->player);
	nc_refresh_color(g_env.from + ((args->arg2 + args->arg3) % IDX_MOD), 4);
	nc_lst_place_blk(&g_env.blink_st, g_env.from + ((args->arg2 + args->arg3) % IDX_MOD));
}
