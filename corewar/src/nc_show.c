/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:34:36 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/31 10:39:42 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
	static size_t	old_cycle;
	size_t			time;
	size_t			part;

	if (g_env.win.state)
		gettimeofday(&g_env.win.clk_new, NULL);
	else
	{
		g_env.win.clk_new = (t_timeval){0, 0};
		g_env.win.clk_old = (t_timeval){0, 0};
		g_env.win.increase = false;
		return ;
	}
	if (g_env.win.clk_new.tv_sec > g_env.win.clk_old.tv_sec &&
		g_env.win.clk_new.tv_usec > g_env.win.clk_old.tv_usec)
	{
		g_env.win.rts = g_env.map.nb_cycles - old_cycle;
		old_cycle = g_env.map.nb_cycles;
		g_env.win.clk_old = g_env.win.clk_new;
	}
	if (g_env.win.clk_new.tv_usec >= g_env.win.clk_old.tv_usec)
		time = g_env.win.clk_new.tv_usec - g_env.win.clk_old.tv_usec;
	else
		time = 1000000 - g_env.win.clk_old.tv_usec + g_env.win.clk_new.tv_usec;
	part = 1000000 / g_env.win.cycl_p_min;
	if ((g_env.map.nb_cycles - old_cycle) * part < time)
		g_env.win.increase = true;
	else
		g_env.win.increase = false;
}

void		nc_show(void)
{
	static bool	rt;

	if (!rt)
	{
		nc_dlc_win();
		nc_generate_show();
		rt = true;
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
	g_env.win.key ? l_key_manage() : 0;
	l_timer();
	nc_show_information();
	wrefresh(g_env.win.w_game);
}
