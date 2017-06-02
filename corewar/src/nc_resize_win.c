/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_resize_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 19:59:34 by folkowic          #+#    #+#             */
/*   Updated: 2017/06/02 14:02:31 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	nc_resize_win(int sig)
{
	(void)sig;
	resizeterm(1200, 1200);
	clear();
	cbreak();
	nodelay(stdscr, true);
	curs_set(false);
	noecho();
	g_env.win.w_main = newwin(68, 257, 0, 0);
	g_env.win.w_mgame = newwin(66, 196, 1, 2);
	g_env.win.w_game = newwin(64, 192, 2, 4);
	g_env.win.w_info = newwin(66, 56, 1, 199);
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
	nc_generate_show();
}
