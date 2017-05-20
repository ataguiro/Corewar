/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:36:32 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/20 19:00:23 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void in_sti(t_process *process)
{
	t_decode *args;
	size_t	curs;

	curs = (process->pc + 1) % MEM_SIZE;
	args = vm_decode_octet(g_env.map.str[curs++]);
	args->param2 == 4 ? args->param2 = 2 : 0;
	args->param3 == 4 ? args->param3 = 2 : 0;
	vm_get_arg(args, &curs);
	args->arg2 = (short)args->arg2;
	args->arg3 = (short)args->arg3;
	if (args->param2 == 1 && args->arg2 > 0 && args->arg2 < 17)
		args->arg2 = process->reg[args->arg2];
	else if ((g_env.map.str[(process->pc + 1) % MEM_SIZE] & 0x30) == 0x30)
		args->arg2 = vm_get_param_val(process->pc + (args->arg2 % IDX_MOD), 4);
	if (args->param3 == 1 && args->arg3 > 0 && args->arg3 < 17)
		args->arg3 = process->reg[args->arg3];
	if (args->param1 && args->param2 && args->param3)
	{
		if (args->arg1 > 0 && args->arg1 < 17)
		{
			vm_replace_int(process->pc + ((args->arg2 + args->arg3) % IDX_MOD),
				process->reg[args->arg1]);
			vm_color_area(process->pc + ((args->arg2 + args->arg3) % IDX_MOD), 4,
					g_env.map.player[process->pc]);
		}
		process->pc = curs % MEM_SIZE;
	}
	else
		process->pc = (process->pc + 2) % MEM_SIZE;
}
