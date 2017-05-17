/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:35:21 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/17 18:57:03 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void in_st(t_player *player)
{
	t_decode *args;
	size_t curs;
	
	curs = (player->pc + 1) % MEM_SIZE;
	args = vm_decode_octet(g_env.map.str[curs++]);
	vm_get_arg(args, &curs);
	if (args->param2 == 1 && args->arg2 > 0 && args->arg2 < 17 &&
							args->arg1 > 0 && args->arg1 < 17)
		player->reg[args->arg2] = player->reg[args->arg1];
	else if (args->param2 == 2 && args->arg1 > 0 && args->arg1 < 17)
	{
		vm_replace_int(player->pc + (args->arg2 % IDX_MOD),
				player->reg[args->arg1]);
		vm_color_area(player->pc + (args->arg2 % IDX_MOD), 4, player->number);
	}
	player->pc = curs % MEM_SIZE;
}
