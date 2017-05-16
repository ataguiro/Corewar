/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:36:22 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/16 12:46:28 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void vm_ldi(t_player *player)
{
	t_decode *args;
	size_t	curs;

	curs = (player->pc + 1) % MEM_SIZE;
	args = vm_decode_octet(g_env.map.str[curs++]);
	ft_printf("len1 %d\n", args->param1);
	ft_printf("len2 %d\n", args->param2);
	ft_printf("len3 %d\n", args->param3);
	vm_get_arg(args, &curs);
	if (args->param1 == DIR_SIZE)
		args->arg1 %= IDX_MOD;
	player->carry = args->arg1 ? true : false;
	if (args->arg2 < 17)
		player->reg[args->arg2] = args->arg1;
	args->arg3 = args->arg1 + args->arg2;
	player->pc = curs % MEM_SIZE;
}
