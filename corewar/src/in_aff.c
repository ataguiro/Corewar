/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:37:14 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/20 23:01:31 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void in_aff(t_process *process)
{
	t_decode *args;
	size_t	curs;

	curs = (process->pc + 1) % MEM_SIZE;
	args = vm_decode_octet(g_env.map.str[curs++], false);
	vm_get_arg(args, &curs, false);
	if (args->param1 == REG_SIZE && args->arg1 > 0 && args->arg1 < 17)
	{
		ft_printf("%c", process->reg[args->arg1] % 256);
		process->pc = process->pc + 3;
	}
	else
		process->pc = process->pc + 2;
}
