/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:37:14 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/12 16:37:15 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void in_aff(t_player *player)
{
	t_decode *args;
	size_t	curs;

	curs = (player->pc + 1) % MEM_SIZE;
	args = vm_decode_octet(g_env.map.str[curs++]);
	vm_get_arg(args, &curs);
	if (args->param1 == REG_SIZE && args->arg1 > 0 && args->arg1 < 17)
	{
		ft_printf("%c", player->reg[args->arg1] % 256);
		player->pc = player->pc + 3;
	}
	else
		player->pc = player->pc + 2;
}
