/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_check_conditions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:50:09 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/15 16:37:59 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_player	*l_kill_process(t_player *play)
{
	t_player *ret;

	if (play->prev)
		play->prev->next = play->next;
	else
		g_env.player = play->next;
	if (play->next)
		play->next->prev = play->prev;
	else
		g_env.player_end = play->prev;
	ret = play->next;
	ft_strdel(&play->str);
	free(play);
	return (ret);
}

static void l_endofgame()
{
	ft_printf("player %d(%s) has won !", g_env.number_last, g_env.name_last);
	while (g_env.player)
		l_kill_process(g_env.player);
	free(g_env.map.str);
	free(g_env.map.player);
	exit(EXIT_SUCCESS);
}

void		vm_check_conditions(void)
{
	t_player 	*play;
	static int	nb_checks = 0;
	int 		total_live;

	total_live = 0;
	play = g_env.player;
	nb_checks++;
	while (play)
	{
		if (!play->nb_live)
			play = l_kill_process(play);
		else
		{
			total_live += play->nb_live;
			play->nb_live = 0;
			play = play->next;
		}
	}
	if (!g_env.player)
		l_endofgame();
	if (total_live >= NBR_LIVE || nb_checks == MAX_CHECKS)
	{
		g_env.map.cycle_to_die -= CYCLE_DELTA;
		nb_checks = 0;
	}
}
