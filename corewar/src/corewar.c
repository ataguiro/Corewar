/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:23:23 by folkowic          #+#    #+#             */
/*   Updated: 2017/06/02 19:04:51 by echo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "server.h"

t_server	g_server;

static void	l_dcl_map(void)
{
	if (!(g_env.map.str = (unsigned char *)malloc(sizeof(*g_env.map.str) *
					(MEM_SIZE + 1))))
		exit(EXIT_FAILURE);
	if (!(g_env.map.player = (int *)malloc(sizeof(*g_env.map.player) *
					(MEM_SIZE + 1))))
		exit(EXIT_FAILURE);
	if (!(g_env.map.cursor= (int *)malloc(sizeof(*g_env.map.cursor) *
					(MEM_SIZE + 1))))
		exit(EXIT_FAILURE);
	ft_bzero(g_env.map.str, MEM_SIZE + 1);
	ft_bzero(g_env.map.player, MEM_SIZE * sizeof(int) + 1);
	ft_bzero(g_env.map.cursor, MEM_SIZE * sizeof(int) + 1);
}

static void	ft_memset_int(int *dst, int src, size_t len)
{
	size_t	i;

	i = ~0;
	while (++i < len)
		dst[i] = src;
}

static void	l_gotoend_lst(t_player **play, t_process **proc)
{
	*play = g_env.player;
	*proc = g_env.process;
	while ((*play)->next)
	{
		*play = (*play)->next;
		*proc = (*proc)->next;
	}
}

static void	l_place_player(void)
{
	t_player	*player;
	t_process	*process;
	char		*str;
	unsigned	n;
	unsigned	part;

	n = 0;
	part = MEM_SIZE / g_env.map.nb_process;
	l_gotoend_lst(&player, &process);
	while (player)
	{
		str = player->str + OFFSET_MAP;
		ft_memcpy(g_env.map.str + (part * n), str, player->header.prog_size);
		ft_memset_int(g_env.map.player + (part * n), g_env.num_player[n + 1],
				player->header.prog_size);
		process->pc = (part * n);
		++g_env.map.cursor[part * n];
		player->number = g_env.num_player[++n];
		process->player = player->number;
		process->reg[1] = player->number;
		player = player->prev;
		process = process->prev;
	}
}

int			main(int argc, char **argv, char **ev)
{
	signal(SIGWINCH, nc_resize_win);
	se_check(ev);
	ft_printf("SERVER MODE : %s\n", g_server.server_mode == ON ? "ON" : "OFF");
	ft_printf("Num players : %d\n", g_server.num_players);
	se_get(argv, argc);
	l_dcl_map();
	if (argc > 1)
	{
		if (g_server.server_mode == ON)
			vm_fill_player(ft_tablen(g_server.se_av), g_server.se_av);
		else
			vm_fill_player(argc, argv);
		if (!g_env.player)
			exit(EXIT_FAILURE);
		vm_ctrl_player(g_env.player);
	}
	if (g_env.map.nb_player > 0 && g_env.map.nb_player < 5)
	{
		l_place_player();
		vm_runtime();
	}
	else
		vm_usage();
	return (0);
}
