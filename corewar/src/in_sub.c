/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:35:40 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/20 23:03:14 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void in_sub(t_process *process)
{
	t_decode *args;
	size_t	curs;

	curs = (process->pc + 1) % MEM_SIZE;
	args = vm_decode_octet(g_env.map.str[curs++], false);
	vm_get_arg(args, &curs, false);
	if ((args->arg1 > 0 && args->arg1 < 17) &&
		(args->arg2 > 0 && args->arg2 < 17) &&
		(args->arg3 > 0 && args->arg3 < 17))
	{
		process->reg[args->arg3] = process->reg[args->arg1] - process->reg[args->arg2];
		if (!process->reg[args->arg3])
			process->carry = 1;
	}
	process->pc = curs % MEM_SIZE;
}
