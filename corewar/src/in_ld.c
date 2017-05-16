/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:35:14 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/16 12:20:33 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	in_ld(t_player *player)
{
	t_decode *args;
	size_t	curs;

	curs = (player->pc + 1) % MEM_SIZE;
	args = vm_decode_octet(g_env.map.str[curs++]);
	vm_get_arg(args, &curs);
	if (args->param1 == DIR_SIZE)
		args->arg1 %= IDX_MOD;
<<<<<<< HEAD
	player->carry = args->arg1 ? false : true;
	if (args->arg2 < 17)
=======
	player->carry = args->arg1 ? true : false;
	if (args->arg2 > 0 && args->arg2 < 17)
>>>>>>> 3644c5630646ed847ce31d923c991d605b1a302a
		player->reg[args->arg2] = args->arg1;
	player->pc = curs % MEM_SIZE;
}
