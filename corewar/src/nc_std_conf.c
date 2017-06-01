/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_std_conf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:40:04 by folkowic          #+#    #+#             */
/*   Updated: 2017/06/01 20:25:43 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	nc_std_conf(void)
{
	wmove(g_env.win.w_info, 41, 2);
	wprintw(g_env.win.w_info, "player %d '%s' has won !", g_env.number_last, 
	g_env.name_last);
	wrefresh(g_env.win.w_info);
	free(g_env.map.str);
	free(g_env.map.player);
	nocbreak();
	nodelay(stdscr, false);
	echo();
	getch();	
	delwin(g_env.win.w_game);
	delwin(g_env.win.w_mgame);
	delwin(g_env.win.w_info);
	delwin(g_env.win.w_main);
	curs_set(true);
	endwin();
	vm_default_mode();
	exit(EXIT_SUCCESS);
}