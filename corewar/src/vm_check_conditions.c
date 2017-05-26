/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_check_conditions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:50:09 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/22 16:11:49 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_process	*l_kill_process(t_process *process)
{
	t_process *ret;

	if (process->prev)
		process->prev->next = process->next;
	else
		g_env.process = process->next;
	if (process->next)
		process->next->prev = process->prev;
	else
		g_env.process_end = process->prev;
	ret = process->next;
	g_env.map.nb_process--;
	free(process);
	return (ret);
}

static void l_endofgame()
{
	ft_printf("player %d(%s) has won !\n", g_env.number_last, g_env.name_last);
	free(g_env.map.str);
	free(g_env.map.player);
	exit(EXIT_SUCCESS);
}

void		vm_check_conditions(void)
{
	t_process 	*process;
	static int	nb_checks = 0;
	static int 	count = 0;

	process = g_env.process;
	++nb_checks;
	while (process)
	{
		if (!process->is_live)
			process = l_kill_process(process);
		else
		{
			process->is_live = false;
			process = process->next;
		}
	}
	if (g_env.map.nb_live >= NBR_LIVE || nb_checks == MAX_CHECKS)
	{
		count++;
		nb_checks = 0;
	}
	g_env.map.cycle_to_die = CYCLE_TO_DIE - (CYCLE_DELTA * count);
	g_env.map.nb_live = 0;
	if (!g_env.process || g_env.map.cycle_to_die <= 0)
		l_endofgame();
}
