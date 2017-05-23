/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:34:36 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/23 21:14:32 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		nc_dlc_win(bool *rt)
{
	g_env.win.w_main = subwin(stdscr, 70, 254, 0, 0);
	g_env.win.w_game = subwin(stdscr, 68, 193, 1, 2);
	g_env.win.w_info = subwin(stdscr, 68, 56, 1, 196);
	box(g_env.win.w_main, ACS_VLINE, ACS_HLINE);
	box(g_env.win.w_game, ACS_VLINE, ACS_HLINE);
	box(g_env.win.w_info, ACS_VLINE, ACS_HLINE);
	*rt = true;
}

void		nc_show(void)
{
	static bool	rt;

	initscr();
	if (!rt)
		nc_dlc_win(&rt);
	refresh();
	getch();
	endwin();
	exit(EXIT_SUCCESS);
}
