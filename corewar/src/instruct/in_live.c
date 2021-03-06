/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:34:57 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/06/27 15:28:47 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	l_find_player(int value)
{
	t_player	*tmp;

	tmp = g_env.player;
	while (tmp)
	{
		if (tmp->number == value)
		{
			tmp->last_live = g_env.map.nb_cycles;
			tmp->total_live++;
			ft_strncpy(g_env.name_last, tmp->header.prog_name,
					PROG_NAME_LENGTH);
			g_env.number_last = tmp->number;
			nc_lst_place_blk(&g_env.blink_live, g_env.from);
			if (!(g_env.cmd & NCURSE))
				ft_printf("+ 1 live for process %d : %s\n",
						tmp->number, tmp->header.prog_name);
			return ;
		}
		tmp = tmp->next;
	}
}

void		in_live(t_process *process)
{
	size_t	curs;

	g_env.from = process->pc;
	process->is_live = true;
	++g_env.map.nb_live;
	curs = (process->pc + 1) % MEM_SIZE;
	l_find_player(vm_get_param_val(curs, 4));
	process->pc = (curs + 4) % MEM_SIZE;
	nc_move_cursor(process->pc, g_env.from);
}
