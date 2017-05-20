/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:35:21 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/20 19:00:29 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void in_st(t_process *process)
{
	t_decode *args;
	size_t curs;

	curs = (process->pc + 1) % MEM_SIZE;
	args = vm_decode_octet(g_env.map.str[curs++]);
	vm_get_arg(args, &curs);
	if (args->param2 == 1 && args->arg2 > 0 && args->arg2 < 17 &&
							args->arg1 > 0 && args->arg1 < 17)
		process->reg[args->arg2] = process->reg[args->arg1];
	else if (args->param2 == 2 && args->arg1 > 0 && args->arg1 < 17)
	{
		vm_replace_int(process->pc + (args->arg2 % IDX_MOD),
				process->reg[args->arg1]);
		vm_color_area(process->pc + (args->arg2 % IDX_MOD), 4,
				g_env.map.player[process->pc]);
	}
	process->pc = curs % MEM_SIZE;
}
