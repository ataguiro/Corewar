/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_generate_show.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:53:40 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/25 18:30:50 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char	*l_hex(unsigned char n)
{
	static char	ret[2];

	ret[0] = '0';
	ret[1] = '0';
	ret[0] = n >> 4;
	if (ret[0] <= 9)
		ret[0] += '0';
	else
		ret[0] += 'a' - 10;
	ret[1] = n & 0xf;
	if (ret[1] <= 9)
		ret[1] += '0';
	else
		ret[1] += 'a' - 10;
	return (ret);
}

void		nc_generate_show(void)
{
	size_t		i;

	printf("num player [1] %d\n", g_env.num_player[1]);
	printf("num player [2] %d\n", g_env.num_player[2]);
	printf("num player [3] %d\n", g_env.num_player[3]);
	wprintw(g_env.win.w_info, "player 1 %d\n", g_env.num_player[2]);
	wprintw(g_env.win.w_info, "player[0] %hhd\n", g_env.map.player[2048]);
	wrefresh(g_env.win.w_info);
	i = -1;
	while (++i < MEM_SIZE)
	{
		if (!g_env.map.player[i])
			wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_0));
		else if (g_env.map.player[i] == g_env.num_player[1])
			wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_1));
		else if (g_env.map.player[i] == g_env.num_player[2])
			wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_2));
		else if (g_env.map.player[i] == g_env.num_player[3])
			wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_3));
		else if (g_env.map.player[i] == g_env.num_player[4])
			wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_4));
		wprintw(g_env.win.w_game, "%s", l_hex((unsigned char)(g_env.map.str[i])));
		wattron(g_env.win.w_game, COLOR_PAIR(0));
		wprintw(g_env.win.w_game, " ");
	}
	wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_C0));
	// wprintw(g_env.win.w_game, "%s", str);
	wrefresh(g_env.win.w_game);
}
