/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:36:14 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/18 16:32:37 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	in_zjmp(t_player *player)
{
	size_t	curs;
	int		value;

	curs = (player->pc + 1) % MEM_SIZE;
	value = (short)vm_get_param_val(curs, 2);
	if (player->carry)
		player->pc = (player->pc + (value % IDX_MOD)) % MEM_SIZE;
	else
		player->pc = (player->pc + 3) % MEM_SIZE;
}
