/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:23:23 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/26 18:11:22 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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

static void	l_place_player(void)
{
	t_player	*player;
	t_process	*process;
	char		*str;
	unsigned	n;
	unsigned	part;

	n = 0;
	part = MEM_SIZE / g_env.map.nb_process;
	player = g_env.player;
	process = g_env.process;
	while (player->next)
	{
		player = player->next;
		process = process->next;
	}
	g_env.process_end = process;
	while (player)
	{
		str = player->str + OFFSET_MAP;
		ft_print_memory(str, player->header.prog_size);
		ft_printf("PROG SIZE %d\n", player->header.prog_size);
		ft_memcpy(g_env.map.str + (part * n), str, player->header.prog_size);
		ft_memset_int(g_env.map.player + (part * n), g_env.num_player[n + 1], player->header.prog_size);
		process->pc = (part * n);
		player->number = g_env.num_player[++n];
		process->player = player->number;
		process->reg[1] = player->number;
		player = player->prev;
		process = process->prev;
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
