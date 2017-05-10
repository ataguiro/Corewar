/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:23:23 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/10 14:34:12 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int		main(int argc, char **argv)
{
	vm_fill_player(argc, argv);
/*	t_player *player2;
	for (t_player *player = g_env.player ; player ; player = player->next)
	{
		ft_print_memory(player->str, player->header.prog_size);
		if (!player->next)
			player2 = player;
	}
	ft_printf("\n");
	for ( ; player2 ; player2 = player2->prev)
	{
		ft_print_memory(player2->str, player2->header.prog_size);
	}*/
	ft_print_memory(g_env.player->str, g_env.player->header.prog_size);
	printf("adr %p\n", g_env.player->str);
	printf("value %x\n", *((int *)(g_env.player->str)));
	g_env.player->header = vm_get_player(g_env.player->str);
	ft_printf("%x\n", g_env.player->header.magic);
	ft_printf("%s\n", g_env.player->header.prog_name);
	ft_printf("%s\n", g_env.player->header.comment);
	for (t_player *player = g_env.player ; player ; player = player->next)
	{
		;
	}
	return (0);
}
