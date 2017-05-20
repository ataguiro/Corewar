/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_check_conditions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:50:09 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/20 19:20:23 by folkowic         ###   ########.fr       */
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
	// ft_strdel(&process->str);
	free(process);
	return (ret);
}

static void l_endofgame()
{
	ft_printf("process %d(%s) has won !", g_env.number_last, g_env.name_last);
	free(g_env.map.str);
	free(g_env.map.player);
	exit(EXIT_SUCCESS);
}

void		vm_check_conditions(void)
{
	t_process 	*process;
	static int	nb_checks = 0;
	int 		total_live;

	total_live = 0;
	process = g_env.process;
	nb_checks++;
	while (process)
	{
		if (!process->nb_live)
			process = l_kill_process(process);
		else
		{
			total_live += process->nb_live;
			process->nb_live = 0;
			process = process->next;
		}
	}
	if (!g_env.process)
		l_endofgame();
	if (total_live >= NBR_LIVE || nb_checks == MAX_CHECKS)
	{
		g_env.map.cycle_to_die -= CYCLE_DELTA;
		nb_checks = 0;
	}
}
