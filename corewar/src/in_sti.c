/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:36:32 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/23 12:41:12 by folkowic         ###   ########.fr       */
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
	size_t		from;

	from = proc->pc;
	curs = (proc->pc + 2) % MEM_SIZE;
	if (!(args = l_valid_sti(proc)))
		return ;
	vm_get_arg(args, &curs, true);
	if (!l_sti_args(proc, args))
		return ;
	if ((g_env.map.str[(from + 1) % MEM_SIZE] & P2_MSK) == P2_IND)
		args->arg2 = vm_get_param_val(from + (args->arg2 % IDX_MOD), 4);
	vm_replace_int(from + ((args->arg2 + args->arg3) % IDX_MOD), args->arg1);
	vm_color_area(from + ((args->arg2 + args->arg3) % IDX_MOD), 4,
						proc->player);
}

// void in_sti(t_process *process)
// {
// 	t_decode *args;
// 	size_t	curs;
//
// 	curs = (process->pc + 1) % MEM_SIZE;
// 	args = vm_decode_octet(g_env.map.str[curs++], false);
// 	args->param2 == 4 ? args->param2 = 2 : 0;
// 	args->param3 == 4 ? args->param3 = 2 : 0;
// 	vm_get_arg(args, &curs, false);
// 	args->arg2 = (short)args->arg2;
// 	args->arg3 = (short)args->arg3;
// 	if (args->param2 == 1 && args->arg2 > 0 && args->arg2 < 17)
// 		args->arg2 = process->reg[args->arg2];
// 	else if ((g_env.map.str[(process->pc + 1) % MEM_SIZE] & 0x30) == 0x30)
// 		args->arg2 = vm_get_param_val(process->pc + (args->arg2 % IDX_MOD), 4);
// 	if (args->param3 == 1 && args->arg3 > 0 && args->arg3 < 17)
// 		args->arg3 = process->reg[args->arg3];
// 	if (args->param1 && args->param2 && args->param3)
// 	{
// 		if (args->arg1 > 0 && args->arg1 < 17)
// 		{
// 			vm_replace_int(process->pc + ((args->arg2 + args->arg3) % IDX_MOD),
// 				process->reg[args->arg1]);
// 			vm_color_area(process->pc + ((args->arg2 + args->arg3) % IDX_MOD), 4,
// 					process->player);//g_env.map.player[process->pc]);
// 		}
// 		process->pc = curs % MEM_SIZE;
// 	}
// 	else
// 		process->pc = (process->pc + 2) % MEM_SIZE;
// }
