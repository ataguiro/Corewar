/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:36:22 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/16 16:33:39 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void vm_ldi(t_player *player)
{
	t_decode *args;
	size_t	curs;

	curs = (player->pc + 1) % MEM_SIZE;
	args = vm_decode_octet(g_env.map.str[curs++]);
	args->param1 == 4 ? args->param1 = 2 : 0;
	args->param2 == 4 ? args->param2 = 2 : 0;
	vm_get_arg(args, &curs);
	player->carry = args->arg1 ? false : true;
	if (args->arg2 < 17)
		player->reg[args->arg2] = args->arg1;
	player->reg[args->arg3] = (int)(args->arg1);
	player->pc = curs % MEM_SIZE;
}
