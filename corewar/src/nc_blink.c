/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_blink.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:51:55 by folkowic          #+#    #+#             */
/*   Updated: 2017/06/04 14:36:54 by folkowic         ###   ########.fr       */
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

// static void		l_print_classic(int player)
// {
// 	if (!player)
// 		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_0));
// 	else if (player == g_env.num_player[1])
// 		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_1_BLK));
// 	else if (player == g_env.num_player[2])
// 		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_2_BLK));
// 	else if (player == g_env.num_player[3])
// 		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_3_BLK));
// 	else if (player == g_env.num_player[4])
// 		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_4_BLK));
// }

static void		l_print_cursor(int player)
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

void	nc_blink(void)
{
	t_blink	*top;

	if (!(g_env.cmd & NCURSE) || !g_env.win.w_main || !g_env.blink)
		return ;
	top = g_env.blink;
	while (g_env.blink)
	{
		if (g_env.blink->len == 1)
		{
			l_find_pos(g_env.blink->pos % MEM_SIZE);
			l_print_cursor(g_env.map.player[g_env.blink->pos % MEM_SIZE]);
			wprintw(g_env.win.w_game, "%s",
				nc_hex((unsigned char)(g_env.map.str[(g_env.blink->pos) % MEM_SIZE])));
		}
		wmove(g_env.win.w_info, 53, 5);
		if (g_env.blink)
		{
			wprintw(g_env.win.w_info, "bink->cd %zu     ", g_env.blink->cd);
			wmove(g_env.win.w_info, 55, 5);
			wprintw(g_env.win.w_info, "bink->pos %zu     ", g_env.blink->pos);
			wmove(g_env.win.w_info, 57, 5);
			wprintw(g_env.win.w_info, "bink %p     ", g_env.blink);
		}
		else
		{
			wprintw(g_env.win.w_info, "                         ");
			wmove(g_env.win.w_info, 55, 5);
			wprintw(g_env.win.w_info, "                         ");
			wmove(g_env.win.w_info, 57, 5);
			wprintw(g_env.win.w_info, "                          ", g_env.blink);
		}
		if (!(--g_env.blink->cd))
		{
			if (g_env.blink == top)
				top = top->next;
			nc_lst_rm_blk(&g_env.blink);
		}
		else
			g_env.blink = g_env.blink->next;
	}
	g_env.blink = top;
}
