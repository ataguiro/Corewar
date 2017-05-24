/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:34:36 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/24 19:22:25 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		nc_dlc_win(bool *rt)
{
	initscr();
	g_env.win.w_main = newwin(70, 254, 0, 0);
	g_env.win.w_mgame = newwin(68, 193, 1, 2);
	g_env.win.w_game = newwin(66, 188, 2, 4);
	g_env.win.w_info = newwin(68, 56, 1, 196);
	box(g_env.win.w_main, ACS_VLINE, ACS_HLINE);
	box(g_env.win.w_mgame, ACS_VLINE, ACS_HLINE);
	box(g_env.win.w_info, ACS_VLINE, ACS_HLINE);
	g_env.win.b_game = subwin(g_env.win.w_mgame, 68, 193, 1, 2);
	g_env.win.b_info = subwin(g_env.win.w_info, 68, 56, 1, 196);
	start_color();
	init_pair(0, COLOR_BLUE, COLOR_RED);
	init_pair(1, COLOR_BLUE, COLOR_RED);
	init_pair(2, COLOR_BLUE, COLOR_RED);
	init_pair(3, COLOR_BLUE, COLOR_RED);
	wattron(g_env.win.w_game, COLOR_PAIR(2));
	wprintw(g_env.win.w_game, "hello world");
	wrefresh(g_env.win.w_main);
	wrefresh(g_env.win.w_mgame);
	wrefresh(g_env.win.w_info);
	wrefresh(g_env.win.w_game);
	*rt = true;
}

void		nc_show(void)
{
	static bool	rt;

	if (!rt)
		nc_dlc_win(&rt);
	 while (1);
	//nc_generate_show();
	// getch();
	sleep(3);
	endwin();
//	exit(EXIT_SUCCESS);
}
