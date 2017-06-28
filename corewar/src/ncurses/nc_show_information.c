/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_show_information.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 12:49:29 by folkowic          #+#    #+#             */
/*   Updated: 2017/06/28 10:40:37 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	l_clear(void)
{
	size_t		i;

	i = 1;
	while (i < 65)
	{
		wmove(g_env.win.w_info, i, 1);
		wprintw(g_env.win.w_info, "%53c", ' ');
		++i;
	}
}

static void	l_print_classic(int player)
{
	if (!player)
		wattron(g_env.win.w_info, COLOR_PAIR(PLAYER_0));
	else if (player == g_env.num_player[1])
		wattron(g_env.win.w_info, COLOR_PAIR(PLAYER_1));
	else if (player == g_env.num_player[2])
		wattron(g_env.win.w_info, COLOR_PAIR(PLAYER_2));
	else if (player == g_env.num_player[3])
		wattron(g_env.win.w_info, COLOR_PAIR(PLAYER_3));
	else if (player == g_env.num_player[4])
		wattron(g_env.win.w_info, COLOR_PAIR(PLAYER_4));
}

static void	l_show_player(size_t *i)
{
	t_player	*play;
	size_t		n;

	play = g_env.player;
	while (play->next)
		play = play->next;
	n = 1;
	while (n <= g_env.map.nb_player)
	{
		wmove(g_env.win.w_info, *i += 2, 2);
		wprintw(g_env.win.w_info, "Player %d : ", g_env.num_player[n]);
		l_print_classic(g_env.num_player[n++]);
		wprintw(g_env.win.w_info, "%s", play->header.prog_name);
		wattron(g_env.win.w_info, COLOR_PAIR(STD_SHOW));
		wmove(g_env.win.w_info, ++(*i), 5);
		wprintw(g_env.win.w_info, "Last live : %19d", play->last_live);
		wmove(g_env.win.w_info, ++(*i), 5);
		wprintw(g_env.win.w_info, "Lives in current period : %5d",
				play->total_live);
		play = play->prev;
	}
}

static void	l_show_ext(size_t *i)
{
	l_show_player(i);
	wmove(g_env.win.w_info, 25, 2);
	wprintw(g_env.win.w_info, "CYCLE_TO_DIE : %d", g_env.map.cycle_to_die);
	wmove(g_env.win.w_info, 27, 2);
	wprintw(g_env.win.w_info, "CYCLE_DELTA : %d", CYCLE_DELTA);
	wmove(g_env.win.w_info, 29, 2);
	wprintw(g_env.win.w_info, "NBR LIVE : %zu", g_env.map.nb_live);
	wmove(g_env.win.w_info, 31, 2);
	wprintw(g_env.win.w_info, "MAX CHECKS : %d", MAX_CHECKS);
}

void		nc_show_information(void)
{
	size_t		i;

	i = 1;
	l_clear();
	wattron(g_env.win.w_game, COLOR_PAIR(0));
	wmove(g_env.win.w_info, i, 2);
	wprintw(g_env.win.w_info, "State : ");
	if (g_env.win.state == PAUSED)
		wprintw(g_env.win.w_info, "PAUSED ");
	else
		wprintw(g_env.win.w_info, "RUNNING");
	wmove(g_env.win.w_info, i += 2, 2);
	wprintw(g_env.win.w_info, "Cycles/second limit : %d", g_env.win.cycl_p_min);
	wmove(g_env.win.w_info, i, 30);
	wprintw(g_env.win.w_info, "(rts) %zu", g_env.win.rts);
	wmove(g_env.win.w_info, i += 3, 2);
	wprintw(g_env.win.w_info, "Cycles : %zu", g_env.map.nb_cycles);
	wmove(g_env.win.w_info, i += 2, 2);
	wprintw(g_env.win.w_info, "Processes : %zu", g_env.map.nb_process);
	l_show_ext(&i);
	wrefresh(g_env.win.w_info);
}
