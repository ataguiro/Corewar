/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:35:47 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/17 16:49:38 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	in_and(t_player *player)
{
	t_decode *args;
	size_t	curs;

	curs = (player->pc + 1) % MEM_SIZE;
	args = vm_decode_octet(g_env.map.str[curs++]);
	vm_get_arg(args, &curs);
	if (args->param1 == 1 && args->arg1 > 0 && args->arg1 < 17)
		args->arg1 = player->reg[args->arg1];
	else if (args->param1 == 2)
	{
		args->arg1 = (short)args->arg1;
		args->arg1 = vm_get_param_val(player->pc + (args->arg1 % IDX_MOD), 4);
	}
	if (args->param2 == 1 && args->arg2 > 0 && args->arg2 < 17)
		args->arg2 = player->reg[args->arg2];
	else if (args->param2 == 2)
	{
		args->arg2 = (short)args->arg2;
		args->arg2 = vm_get_param_val(player->pc + (args->arg2 % IDX_MOD), 4);
	}
	if (args->param1 && args->param2 && args->param3)
	{
		if (args->param3 == 1 && args->arg3 > 0 && args->arg3 < 17)
		{
			player->reg[args->arg3] = args->arg1 & args->arg2;
			player->carry = player->reg[args->arg3] ? false : true;
		}
		player->pc = curs % MEM_SIZE;
	}
	else
	{
		player->pc = (player->pc + 2) % MEM_SIZE;
		player->carry = false;
	}
}