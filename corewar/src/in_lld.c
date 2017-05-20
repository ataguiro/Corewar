/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:36:49 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/20 23:02:31 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void in_lld(t_process *process)
{
	t_decode *args;
	size_t	curs;

	curs = (process->pc + 1) % MEM_SIZE;
	args = vm_decode_octet(g_env.map.str[curs++], false);
	vm_get_arg(args, &curs, false);
	if (args->param1 == IND_SIZE)
		args->arg1 = vm_get_param_val(process->pc + args->arg1, 4);
	if (args->param1 && args->param2 && args->arg2 > 0 && args->arg2 < 17)
	{
		process->carry = args->arg1 ? false : true;
		process->reg[args->arg2] = args->arg1;
	}
	process->pc = curs % MEM_SIZE;
}
