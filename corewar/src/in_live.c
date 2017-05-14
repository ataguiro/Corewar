/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:34:57 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/14 15:15:49 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static bool	l_find_player(int value)
{
	t_player	*player;

	player = g_env.player;
	while (player)
	{
		if (player->number == value)
		{
			++player->nb_live;
			ft_printf("+ 1 live for player %d : %s\n",
					player->number, player->header.prog_name);
			return (true);
		}
		player = player->next;
	}
	return (false);
}

void vm_live(t_player *player)
{
	int		*num_player;
	int		value;

	num_player = (int *)&g_env.map.str[player->pc + 1];
	value = (int)vm_reverse_trame((char *)g_env.map.str + player->pc,
			sizeof(int));
	l_find_player(value);
	player->pc += 5;
}
