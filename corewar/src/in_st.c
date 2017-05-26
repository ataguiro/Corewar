/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:35:21 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/26 17:51:10 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_decode	*l_valid_st(t_process *proc)
{
	unsigned char 	ocp;
	t_decode 		*args;

	ocp = g_env.map.str[(proc->pc + 1) % MEM_SIZE];
	args = vm_decode_octet(ocp, false);
	proc->pc = (proc->pc + args->param1 + args->param2 + 2) % MEM_SIZE;
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
	t_decode *args;
	size_t	curs;
	size_t	from;

	from = proc->pc;
	curs = (proc->pc + 2) % MEM_SIZE;
	if (!(args = l_valid_st(proc)))
		return ;
	vm_get_arg(args, &curs, false);
	if (!l_st_args(proc, args))
		return ;
	if (args->param2 == REG_SIZE)
		proc->reg[args->arg2] = args->arg1;
	else
	{
		vm_replace_int(from + (args->arg2 % IDX_MOD), args->arg1);
		vm_color_area(from + (args->arg2 % IDX_MOD), 4, proc->player);
	}
	nc_move_cursor(proc, from);
}