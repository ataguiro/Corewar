/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_refresh_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 17:48:03 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/31 11:33:46 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	l_find_pos(size_t target)
{
	size_t	x;
	size_t	y;
	size_t	nb_sp;

	y = target / LEN_LINE;
	nb_sp = target;
	target = target * 2 + nb_sp;
	x = target % LEN_LINE_CHAR;
	wmove(g_env.win.w_game, y, x);
}

static void		l_print_classic(int player)
{
	if (!player)
		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_0));
	else if (player == g_env.num_player[1])
		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_1));
	else if (player == g_env.num_player[2])
		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_2));
	else if (player == g_env.num_player[3])
		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_3));
	else if (player == g_env.num_player[4])
		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_4));
}

void		nc_refresh_color(size_t from, size_t len)
{
	size_t	i;

	if (!(g_env.cmd & NCURSE) || !g_env.win.w_main)
		return ;
	l_find_pos(from);
	i = ~0;
	while (++i < len)
	{
		l_find_pos((from + i) % MEM_SIZE);
		l_print_classic(g_env.map.player[from % MEM_SIZE]);
		wprintw(g_env.win.w_game, "%s",
				nc_hex((unsigned char)(g_env.map.str[(from + i) % MEM_SIZE])));
		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_0));
		wprintw(g_env.win.w_game, " ");
	}
}
