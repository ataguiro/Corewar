/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:34:36 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/29 21:47:31 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void nc_init_color(void)
{
	start_color();
	init_color(COLOR_BLUE, 250, 350, 1000);
	init_color(COLOR_GRAY, 200, 200, 200);
	init_pair(PLAYER_1, COLOR_GREEN, COLOR_BLACK);
	init_pair(PLAYER_2, COLOR_BLUE, COLOR_BLACK);
	init_pair(PLAYER_3, COLOR_RED, COLOR_BLACK);
	init_pair(PLAYER_4, COLOR_CYAN, COLOR_BLACK);
	init_pair(PLAYER_0, COLOR_GRAY, COLOR_BLACK);
	init_pair(PLAYER_C1, COLOR_BLACK, COLOR_GREEN);
	init_pair(PLAYER_C2, COLOR_BLACK, COLOR_BLUE);
	init_pair(PLAYER_C3, COLOR_BLACK, COLOR_RED);
	init_pair(PLAYER_C4, COLOR_BLACK, COLOR_CYAN);
	init_pair(PLAYER_C0, COLOR_BLACK, COLOR_GRAY);
}

static void		nc_dlc_win(bool *rt)
{
	initscr();
	cbreak();
	// keypad(stdscr, TRUE);
	nodelay(stdscr, true);
	curs_set(0);
	noecho();
	g_env.win.w_main = newwin(68, 257, 0, 0);
	g_env.win.w_mgame = newwin(66, 196, 1, 2);
	g_env.win.w_game = newwin(64, 192, 2, 4);
	g_env.win.w_info = newwin(66, 56, 1, 199);
	box(g_env.win.w_main, ACS_VLINE, ACS_HLINE);
	box(g_env.win.w_mgame, ACS_VLINE, ACS_HLINE);
	box(g_env.win.w_info, ACS_VLINE, ACS_HLINE);
	g_env.win.b_game = subwin(g_env.win.w_mgame, 68, 193, 1, 2);
	g_env.win.b_info = subwin(g_env.win.w_info, 68, 56, 1, 196);
	nc_init_color();
	refresh();
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
	{
		nc_dlc_win(&rt);
		nc_generate_show();
	}
	else
	{
		g_env.win.key = wgetch(stdscr);
	}
	nc_show_information();
	wrefresh(g_env.win.w_game);
}
