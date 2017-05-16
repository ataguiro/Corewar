/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:35:34 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/12 16:35:35 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void in_add(t_player *player)
{
	t_decode *args;
	size_t	curs;

	curs = (player->pc + 1) % MEM_SIZE;
	args = vm_decode_octet(g_env.map.str[curs++]);
	vm_get_arg(args, &curs);
	if ((args->arg1 > 0 && args->arg1 < 17) &&
		(args->arg2 > 0 && args->arg2 < 17) &&
		(args->arg3 > 0 && args->arg3 < 17))
	{
		player->reg[args->arg3] = player->reg[args->arg1] + player->reg[args->arg2];
		if (!player->reg[args->arg3])
			player->carry = 1;
	}
	player->pc = curs % MEM_SIZE;
}
