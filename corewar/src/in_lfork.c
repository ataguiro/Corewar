/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:37:08 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/15 20:36:43 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void in_lfork(t_player *player)
{
	size_t		curs;
	int			value;

	curs = (player->pc + 1) % MEM_SIZE;
	value = vm_get_param_val(curs, 2);
	vm_lst_add_cpy(&player);
	player->pc = (player->pc + 3) % MEM_SIZE;
	player->next->cycles_cd++;
	player->next->pc = (player->next->pc + value) % MEM_SIZE;
}
