/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_instruct_call.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 18:32:12 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/14 20:58:17 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void 	vm_call_instruct(t_player *player)
{
	//appelle la fonction suivant l' index et l' opcode sur lequel il se trouve
	if (g_env.map.str[player->pc] > 0 && g_env.map.str[player->pc] < 17)
	{
		g_env.instruction[g_env.map.str[player->pc]](player);
		// db_show_reg(player);
	}
	else
		player->pc++;
}
