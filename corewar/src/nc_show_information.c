/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_show_information.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 12:49:29 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/31 14:28:14 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	l_clear(void)
{
	size_t	i;

	i = 1;
	while (i < 65)
	{
		wmove(g_env.win.w_info, i, 2);
		wprintw(g_env.win.w_info, "                                          ");
		i += 2;
	}
}

void		nc_show_information(void)
{
	l_clear();
	wattron(g_env.win.w_game, COLOR_PAIR(0));
	wmove(g_env.win.w_info, 1, 2);
	wprintw(g_env.win.w_info, "State : ");
	if (g_env.win.state == PAUSED)
		wprintw(g_env.win.w_info, "PAUSED ");
	else
		wprintw(g_env.win.w_info, "RUNNING");
	wmove(g_env.win.w_info, 3, 2);
	wprintw(g_env.win.w_info, "Cycles/second limit : %d", g_env.win.cycl_p_min);
	wmove(g_env.win.w_info, 5, 2);
	wprintw(g_env.win.w_info, "PROCESS : %zu", g_env.map.nb_process);
	wmove(g_env.win.w_info, 7, 2);
	wprintw(g_env.win.w_info, "CYCLE : %zu", g_env.map.nb_cycles);
	wmove(g_env.win.w_info, 25, 2);
	wprintw(g_env.win.w_info, "CYCLE_TO_DIE : %d", g_env.map.cycle_to_die);
	wmove(g_env.win.w_info, 27, 2);
	wprintw(g_env.win.w_info, "CYCLE_DELTA : %d", CYCLE_DELTA);
	wmove(g_env.win.w_info, 29, 2);
	wprintw(g_env.win.w_info, "NBR LIVE : %zu", g_env.map.nb_live);
	wmove(g_env.win.w_info, 31, 2);
	wprintw(g_env.win.w_info, "MAX CHECKS : %d", MAX_CHECKS);
	wmove(g_env.win.w_info, 43, 2);
	wprintw(g_env.win.w_info, "RTS %zu", g_env.win.rts);
	wmove(g_env.win.w_info, 45, 2);
	wprintw(g_env.win.w_info, "trace %zu", g_env.map.cursor[3931]);
	wmove(g_env.win.w_info, 47, 2);
	wprintw(g_env.win.w_info, "trace %hhx", g_env.map.str[3931]);
	wmove(g_env.win.w_info, 49, 2);
	wprintw(g_env.win.w_info, "trace %zu", g_env.map.cursor[3930]);
	wmove(g_env.win.w_info, 51, 2);
	wprintw(g_env.win.w_info, "trace %hhx", g_env.map.str[3930]);
	wmove(g_env.win.w_info, 53, 2);
	wprintw(g_env.win.w_info, "trace %zu", g_env.map.cursor[3929]);
	wmove(g_env.win.w_info, 55, 2);
	wprintw(g_env.win.w_info, "trace %hhx", g_env.map.str[3929]);
	wrefresh(g_env.win.w_info);	
}
