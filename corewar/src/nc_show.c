/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:34:36 by folkowic          #+#    #+#             */
/*   Updated: 2017/06/02 15:04:32 by folkowic         ###   ########.fr       */
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

static void	l_real_time(size_t nb_cycles, size_t time)
{
	double	time_sec;

	time_sec = time / 1000000;
	g_env.win.rts = nb_cycles / time_sec;
}

static void	l_aff_increase(void)
{
	double			part;
	static size_t	old_cycle;
	size_t			time_new;
	size_t			time_old;
	size_t			time;

	time_new = g_env.win.clk_new.tv_sec * 1000000 + g_env.win.clk_new.tv_usec;
	time_old = g_env.win.clk_old.tv_sec * 1000000 + g_env.win.clk_old.tv_usec;
	time = time_new - time_old;
	if (g_env.win.clk_new.tv_sec > g_env.win.clk_old.tv_sec &&
		g_env.win.clk_new.tv_usec >= g_env.win.clk_old.tv_usec)
	{
		l_real_time(g_env.map.nb_cycles - old_cycle, time);
		old_cycle = g_env.map.nb_cycles;
		g_env.win.clk_old = g_env.win.clk_new;
	}
	part = 1000000 / g_env.win.cycl_p_min;
	if ((g_env.map.nb_cycles - old_cycle) * part < time)
		g_env.win.increase = true;
	else
		g_env.win.increase = false;
}

static void	l_timer(void)
{
	if (g_env.win.state)
		gettimeofday(&g_env.win.clk_new, NULL);
	else
	{
		g_env.win.clk_new = (t_timeval){0, 0};
		g_env.win.clk_old = (t_timeval){0, 0};
		g_env.win.increase = false;
		return ;
	}
	l_aff_increase();
}

void		nc_show(void)
{
	static bool	rt;

	g_env.dump_cycle = 0;
	if (!rt)
	{
		nc_dlc_win();
		// nc_generate_show();
		nc_refresh_color(0, MEM_SIZE);
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
