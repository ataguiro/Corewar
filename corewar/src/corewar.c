/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:23:23 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/15 18:33:42 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	l_dcl_map(void)
{
	if (!(g_env.map.str = (unsigned char *)malloc(sizeof(*g_env.map.str) *
					(MEM_SIZE + 1))))
		exit(EXIT_FAILURE);
	if (!(g_env.map.player = (unsigned char *)malloc(sizeof(*g_env.map.player) *
					(MEM_SIZE + 1))))
		exit(EXIT_FAILURE);
	ft_bzero(g_env.map.str, MEM_SIZE + 1);
	ft_bzero(g_env.map.player, MEM_SIZE + 1);
}

static void	l_place_player(void)
{
	t_player	*player;
	char		*str;
	unsigned	n;
	unsigned	part;

	n = 0;
	part = MEM_SIZE / g_env.map.nb_player;
	player = g_env.player;
	while (player->next)
		player = player->next;
	g_env.player_end = player;
	while (player)
	{
		str = player->str + OFFSET_MAP;
		ft_print_memory(str, player->header.prog_size);
		ft_memcpy(g_env.map.str + (part * n), str, player->header.prog_size);
		ft_memset(g_env.map.player + (part * n), g_env.num_player[n + 1],
				player->header.prog_size);
		player->pc = (part * n);
		player->number = g_env.num_player[++n];
		ft_printf("num assoss %d\n", g_env.num_player[n - 1]);
		player = player->prev;
	}
}

int			main(int argc, char **argv)
{
	l_dcl_map();
	if (argc > 1)
	{
		vm_fill_player(argc, argv);
		if (!g_env.player)
			exit(EXIT_FAILURE);
		g_env.player->header = vm_get_player(g_env.player->str);
		db_show_lst(g_env.player);
		vm_ctrl_player(g_env.player);
	}
	else
		vm_usage();
	if (g_env.map.nb_player > 0 && g_env.map.nb_player < 5)
	{
		l_place_player();
		vm_runtime();
	}
	return (0);
}
