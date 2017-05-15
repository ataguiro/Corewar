/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:36:38 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/15 12:10:44 by folkowic         ###   ########.fr       */
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
	n = vm_lst_new();
	ft_memcpy(n, player, sizeof(*player));
	vm_lst_add(&player, n);
	player->pc = (player->pc + 3) % MEM_SIZE;
	player->next->pc = (player->next->pc + value) % MEM_SIZE;
}
