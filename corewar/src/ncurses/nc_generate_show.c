/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_generate_show.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:53:40 by folkowic          #+#    #+#             */
/*   Updated: 2017/06/06 14:52:02 by folkowic         ###   ########.fr       */
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

static void	l_print_classic(int player)
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

static void	l_print_cursor(int player)
{
	if (!player)
		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_C0));
	else if (player == g_env.num_player[1])
		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_C1));
	else if (player == g_env.num_player[2])
		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_C2));
	else if (player == g_env.num_player[3])
		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_C3));
	else if (player == g_env.num_player[4])
		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_C4));
}

static int	l_cmp_cursor(t_process *process, size_t target)
{
	t_process		*tmp;

	tmp = process;
	while (process)
	{
		if (process->pc == target)
		{
			l_print_cursor(g_env.map.player[target]);
			return (true);
		}
		process = process->next;
	}
	return (false);
}

void		nc_generate_show(void)
{
	size_t		i;

	wmove(g_env.win.w_game, 0, 0);
	wrefresh(g_env.win.w_info);
	i = -1;
	while (++i < MEM_SIZE)
	{
		if (!l_cmp_cursor(g_env.process, i))
			l_print_classic(g_env.map.player[i]);
		wprintw(g_env.win.w_game, "%s",
			l_hex((unsigned char)(g_env.map.str[i])));
		wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_0));
		wprintw(g_env.win.w_game, " ");
	}
	wattron(g_env.win.w_game, COLOR_PAIR(PLAYER_C0));
	wrefresh(g_env.win.w_game);
}
