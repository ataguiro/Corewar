/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:35:14 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/14 20:59:47 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	in_ld(t_player *player)
{
	t_decode *args;
	size_t	curs;
	int		arg1;
	int		arg2;

	curs = (player->pc + 1) % MEM_SIZE;
	args = vm_decode_octet(g_env.map.str[curs++]);
	arg1 = vm_get_param_val(curs, args->param1);
	if (args->param1 == DIR_SIZE)
		arg1 %= IDX_MOD;
	curs = (curs + args->param1) % MEM_SIZE;
	arg2 = vm_get_param_val(curs, args->param2);
	curs = (curs + args->param2) % MEM_SIZE;
	player->pc = curs % MEM_SIZE;
	player->carry = arg1 ? true : false;
	player->reg[arg2] = arg1;
}
