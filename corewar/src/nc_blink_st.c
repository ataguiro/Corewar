/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_blink_st.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 16:32:16 by folkowic          #+#    #+#             */
/*   Updated: 2017/06/04 16:43:02 by folkowic         ###   ########.fr       */
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
		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_1_BLK));
	else if (player == g_env.num_player[2])
		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_2_BLK));
	else if (player == g_env.num_player[3])
		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_3_BLK));
	else if (player == g_env.num_player[4])
		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_4_BLK));
}

void	nc_blink_st(void)
{
	t_blink	*top;
	size_t	i;

	if (!(g_env.cmd & NCURSE) || !g_env.win.w_main || !g_env.blink_st)
		return ;
	top = g_env.blink_st;
	while (g_env.blink_st)
	{
		l_find_pos(g_env.blink_st->pos % MEM_SIZE);
		l_print_classic(g_env.map.player[g_env.blink_st->pos % MEM_SIZE]);
		i = ~0;
		while (++i < 4)
			wprintw(g_env.win.w_game, "%s ",
				nc_hex((unsigned char)
				(g_env.map.str[(g_env.blink_st->pos + i) % MEM_SIZE])));
		if (!(--g_env.blink_st->cd))
		{
			g_env.blink_st == top ? top = top->next : 0;
			nc_lst_rm_blk(&g_env.blink_st, 4);
		}
		else
			g_env.blink_st = g_env.blink_st->next;
	}
	g_env.blink_st = top;
}