/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:35:21 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/06/06 15:15:46 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_decode	*l_valid_st(t_process *proc)
{
	t_decode		*args;
	unsigned char	ocp;

	ocp = g_env.map.str[(proc->pc + 1) % MEM_SIZE];
	args = vm_decode_octet(ocp, false);
	proc->pc = (proc->pc + args->param1 + args->param2 + 2) % MEM_SIZE;
	nc_move_cursor(proc->pc, g_env.from);
	if ((ocp & P1_MSK) != P1_REG || (ocp & P2_MSK) == P1_DIR)
		return (false);
	return (args);
}

static bool		l_st_args(t_process *proc, t_decode *args)
{
	if (args->arg1 < 1 || args->arg1 > 16)
		return (false);
	args->arg1 = proc->reg[args->arg1];
	if (args->param2 == REG_SIZE)
	{
		if (args->arg2 < 1 || args->arg2 > 16)
			return (false);
	}
	return (true);
}

void			in_st(t_process *proc)
{
	t_decode	*args;
	size_t		curs;

	g_env.from = proc->pc;
	curs = (proc->pc + 2) % MEM_SIZE;
	if (!(args = l_valid_st(proc)))
		return ;
	vm_get_arg(args, &curs);
	if (!l_st_args(proc, args))
		return ;
	if (args->param2 == REG_SIZE)
		proc->reg[args->arg2] = args->arg1;
	else
	{
		vm_replace_int(g_env.from + (args->arg2 % IDX_MOD), args->arg1);
		vm_color_area(g_env.from + (args->arg2 % IDX_MOD), 4, proc->player);
		nc_refresh_color(g_env.from + (args->arg2 % IDX_MOD), 4);
		nc_lst_place_blk(&g_env.blink_st, g_env.from + (args->arg2 % IDX_MOD));
	}
}
