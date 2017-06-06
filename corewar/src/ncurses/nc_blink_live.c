/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_blink_live.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:51:55 by folkowic          #+#    #+#             */
/*   Updated: 2017/06/06 14:48:35 by folkowic         ###   ########.fr       */
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

static void	l_print_cursor(int player)
{
	if (!player)
		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_C0));
	else if (player == g_env.num_player[1])
		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_C1_BLK));
	else if (player == g_env.num_player[2])
		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_C2_BLK));
	else if (player == g_env.num_player[3])
		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_C3_BLK));
	else if (player == g_env.num_player[4])
		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_C4_BLK));
}

void		nc_blink_live(void)
{
	t_blink	*top;

	if (!(g_env.cmd & NCURSE) || !g_env.win.w_main || !g_env.blink_live)
		return ;
	top = g_env.blink_live;
	while (g_env.blink_live)
	{
		l_find_pos(g_env.blink_live->pos % MEM_SIZE);
		l_print_cursor(g_env.map.player[g_env.blink_live->pos % MEM_SIZE]);
		wprintw(g_env.win.w_game, "%s",
			nc_hex((unsigned char)(g_env.map.str[(g_env.blink_live->pos)
				% MEM_SIZE])));
		if (!(--g_env.blink_live->cd))
		{
			g_env.blink_live == top ? top = top->next : 0;
			nc_lst_rm_blk(&g_env.blink_live, 1);
		}
		else
			g_env.blink_live = g_env.blink_live->next;
	}
	g_env.blink_live = top;
}
