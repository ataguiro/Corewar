/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:34:57 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/15 12:07:19 by folkowic         ###   ########.fr       */
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
			ft_strncpy(g_env.name_last, player->header.prog_name, PROG_NAME_LENGTH);
			g_env.number_last = player->number;
			ft_printf("+ 1 live for player %d : %s\n",
					player->number, player->header.prog_name);
			return (true);
		}
		player = player->next;
	}
	return (false);
}

void	in_live(t_player *player)
{
	size_t	curs;
	int		value;

	++player->nb_live;
	curs = (player->pc + 1) % MEM_SIZE;
	value = vm_get_param_val(curs, 4);
	l_find_player(value);
	player->pc = (curs + 4) % MEM_SIZE;
}
