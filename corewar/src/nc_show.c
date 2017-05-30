/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:34:36 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/30 18:38:06 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void l_init_color(void)
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

static void		l_dlc_win(bool *rt)
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
	l_init_color();
	refresh();
	wrefresh(g_env.win.w_main);
	wrefresh(g_env.win.w_mgame);
	wrefresh(g_env.win.w_info);
	wrefresh(g_env.win.w_game);
	*rt = true;
}

static void	l_key_manage(void)
{
	if (g_env.win.key == KEY_SP && !g_env.win.state)
		g_env.win.state = true;
	else if (g_env.win.key == KEY_SP)
		g_env.win.state = false;
	g_env.win.step = g_env.win.key == KEY_S ? true : false;
	if (g_env.win.key == KEY_Q)
		g_env.win.cycl_p_min -= 10;
	else if (g_env.win.key == KEY_W)
		--g_env.win.cycl_p_min;
	else if (g_env.win.key == KEY_E)
		++g_env.win.cycl_p_min;
	else if (g_env.win.key == KEY_R)
		g_env.win.cycl_p_min += 10;
	if (g_env.win.cycl_p_min < 1)
		g_env.win.cycl_p_min = 1;
	else if (g_env.win.cycl_p_min > 1000)
		g_env.win.cycl_p_min = 1000;
}

static void	l_timer(void)
{
	static size_t		old_cycle;
	static size_t		rts;

	gettimeofday(&g_env.win.clk_new, NULL);
	if (g_env.win.clk_new.tv_sec > g_env.win.clk_old.tv_sec &&
		g_env.win.clk_new.tv_usec > g_env.win.clk_old.tv_usec)
	{
		g_env.win.increase = true;
		rts = g_env.map.nb_cycles - old_cycle;
		old_cycle = g_env.map.nb_cycles;
		g_env.win.clk_old = g_env.win.clk_new;
	}
	wmove(g_env.win.w_info, 39, 2);
	wprintw(g_env.win.w_info, "                           ");
	wmove(g_env.win.w_info, 39, 2);
	wprintw(g_env.win.w_info, "Timer %zu", g_env.win.clk_new.tv_usec);
	wmove(g_env.win.w_info, 41, 2);
	wprintw(g_env.win.w_info, "                                              ");
	wmove(g_env.win.w_info, 41, 2);
	wprintw(g_env.win.w_info, "Timer %zu", g_env.win.clk_new.tv_sec);
	wmove(g_env.win.w_info, 43, 2);
	wprintw(g_env.win.w_info, "                                              ");
	wmove(g_env.win.w_info, 43, 2);
	wprintw(g_env.win.w_info, "RTS %zu", rts);
}
void		nc_show(void)
{
	static bool	rt;

	if (!rt)
	{
		l_dlc_win(&rt);
		nc_generate_show();
	}
	else
		g_env.win.key = wgetch(stdscr);
	if (g_env.win.key > 0)
	{
		wmove(g_env.win.w_info, 37, 2);
		wprintw(g_env.win.w_info, "               ");
		wmove(g_env.win.w_info, 37, 2);
		wprintw(g_env.win.w_info, "key %d", g_env.win.key);
	}
	l_timer();
	g_env.win.key ? l_key_manage() : 0;
	nc_show_information();
	wrefresh(g_env.win.w_game);
}
