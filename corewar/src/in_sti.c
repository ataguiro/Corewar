/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:36:32 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/17 18:58:40 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void in_sti(t_player *player)
{
	t_decode *args;
	size_t	curs;

	curs = (player->pc + 1) % MEM_SIZE;
	args = vm_decode_octet(g_env.map.str[curs++]);
	args->param2 == 4 ? args->param2 = 2 : 0;
	args->param3 == 4 ? args->param3 = 2 : 0;
	vm_get_arg(args, &curs);
	args->arg2 = (short)args->arg2;
	args->arg3 = (short)args->arg3;
	if (args->param2 == 1 && args->arg2 > 0 && args->arg2 < 17)
		args->arg2 = player->reg[args->arg2];
	else if ((g_env.map.str[(player->pc + 1) % MEM_SIZE] & 0x30) == 0x30)
		args->arg2 = vm_get_param_val(player->pc + (args->arg2 % IDX_MOD), 4);
	if (args->param3 == 1 && args->arg3 > 0 && args->arg3 < 17)
		args->arg3 = player->reg[args->arg3];
	if (args->param1 && args->param2 && args->param3)
	{
		if (args->arg1 > 0 && args->arg1 < 17)
		{
			vm_replace_int(player->pc + ((args->arg2 + args->arg3) % IDX_MOD),
				player->reg[args->arg1]);
			vm_color_area(player->pc + ((args->arg2 + args->arg3) % IDX_MOD), 4,
					player->number);
		}
		player->pc = curs % MEM_SIZE;
	}
	else
		player->pc = (player->pc + 2) % MEM_SIZE;
}
