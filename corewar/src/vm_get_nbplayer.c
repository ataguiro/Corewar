/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_get_nbplayer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:36:08 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/15 18:16:47 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int 	nb_is_free(int nb_to_check)
{
	t_player *tmp;

	tmp = g_env.player;
	while (tmp)
	{
		if (tmp->number == nb_to_check)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void 		vm_get_nbplayer(void)
{
	static int nb_player = 1;

	if (g_env.cmd & NB_PLAY)
	{
		//g_env.player->number = g_env.option_nb_play;
		g_env.num_player[nb_player] = g_env.option_nb_play;
		g_env.cmd ^= NB_PLAY;
	}
	else
	{
		while (!nb_is_free(nb_player))
			++nb_player;
//		g_env.player->number = nb_player++;
		g_env.num_player[nb_player] = nb_player;
		++nb_player;
	}	
}

