/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_resize_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 19:59:34 by folkowic          #+#    #+#             */
/*   Updated: 2017/06/02 15:54:34 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	l_clear(void)
{
	resizeterm(1200, 1200);
	initscr();
	clear();
	wclear(g_env.win.w_main);
	wclear(g_env.win.w_mgame);
	wclear(g_env.win.w_info);
	wclear(g_env.win.w_game);
	g_env.win.w_main = newwin(68, 257, 0, 0);
	g_env.win.w_mgame = newwin(66, 196, 1, 2);
	g_env.win.w_game = newwin(64, 192, 2, 4);
	g_env.win.w_info = newwin(66, 56, 1, 199);
}

void	nc_resize_win(int sig)
{
	(void)sig;
	
	l_clear();
	cbreak();
	nodelay(stdscr, true);
	curs_set(false);
	noecho();
	if (!g_env.win.w_main || !g_env.win.w_mgame || !g_env.win.w_game || !g_env.win.w_info)
		exit(EXIT_FAILURE);
	box(g_env.win.w_main, ACS_VLINE, ACS_HLINE);
	box(g_env.win.w_mgame, ACS_VLINE, ACS_HLINE);
	box(g_env.win.w_info, ACS_VLINE, ACS_HLINE);
	refresh();
	wrefresh(g_env.win.w_main);
	wrefresh(g_env.win.w_mgame);
	wrefresh(g_env.win.w_info);
	wrefresh(g_env.win.w_game);
	if (g_env.win.w_main)
		nc_refresh_color(0, MEM_SIZE);
}
