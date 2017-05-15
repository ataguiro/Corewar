/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:36:38 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/15 14:08:59 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void in_fork(t_player *player)
{
	t_player	*n;
	size_t		curs;
	int			value;

	curs = (player->pc + 1) % MEM_SIZE;
	value = vm_get_param_val(curs, 2) % IDX_MOD;
	vm_lst_add_new(&player);
	ft_memcpy(n, player, sizeof(*player));
	n->str = ft_strdup(player->str);
	player->pc = (player->pc + 3) % MEM_SIZE;
	player->next->pc = (player->next->pc + value) % MEM_SIZE;
/*	for (t_player *play = g_env.player ; play ; play = play->next)
		db_show_reg(play);*/
}
