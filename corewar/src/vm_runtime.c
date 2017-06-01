/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_runtime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:36:18 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/06/01 20:58:10 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	l_init_cycle_size(void)
{
	g_env.cycles_size[0] = 0;
	g_env.cycles_size[1] = 10;
	g_env.cycles_size[2] = 5;
	g_env.cycles_size[3] = 5;
	g_env.cycles_size[4] = 10;
	g_env.cycles_size[5] = 10;
	g_env.cycles_size[6] = 6;
	g_env.cycles_size[7] = 6;
	g_env.cycles_size[8] = 6;
	g_env.cycles_size[9] = 20;
	g_env.cycles_size[10] = 25;
	g_env.cycles_size[11] = 25;
	g_env.cycles_size[12] = 800;
	g_env.cycles_size[13] = 10;
	g_env.cycles_size[14] = 50;
	g_env.cycles_size[15] = 1000;
	g_env.cycles_size[16] = 2;
}

static void	l_init_instructions(void)
{
	g_env.instruction[0] = NULL;
	g_env.instruction[1] = &in_live;
	g_env.instruction[2] = &in_ld;
	g_env.instruction[3] = &in_st;
	g_env.instruction[4] = &in_add;
	g_env.instruction[5] = &in_sub;
	g_env.instruction[6] = &in_and;
	g_env.instruction[7] = &in_or;
	g_env.instruction[8] = &in_xor;
	g_env.instruction[9] = &in_zjmp;
	g_env.instruction[10] = &in_ldi;
	g_env.instruction[11] = &in_sti;
	g_env.instruction[12] = &in_fork;
	g_env.instruction[13] = &in_lld;
	g_env.instruction[14] = &in_lldi;
	g_env.instruction[15] = &in_lfork;
	g_env.instruction[16] = &in_aff;
}

static void	l_init_process_cycles(void)
{
	t_process *process;

	process = g_env.process;
	l_init_cycle_size();
	while (process)
	{
		process->instr = g_env.map.str[process->pc];
		process->cycles_cd = g_env.cycles_size[g_env.map.str[process->pc]];
		process = process->next;
	}
}

static void	l_do_actions(void)
{
	t_process *proc;

	proc = g_env.process;
	while (proc)
	{
		if (!proc->cycles_cd)
		{			
			if (g_env.map.str[proc->pc] > 0 &&
				g_env.map.str[proc->pc] < 17)
			{
				proc->cycles_cd = g_env.cycles_size[g_env.map.str[proc->pc]];
				proc->instr = g_env.map.str[proc->pc];
			}
			else
				++proc->cycles_cd;
		}
		if (!--proc->cycles_cd)
			vm_call_instruct(proc);
		proc = proc->next;
	}
}

void		vm_runtime(void)
{
	l_init_process_cycles();
	l_init_instructions();
	g_env.map.cycle_to_die = CYCLE_TO_DIE;
	while (true)
	{
		if ((g_env.cmd & NCURSE && (true || g_env.win.increase || g_env.win.step)) || 
			(g_env.cmd & DUMP && g_env.dump_cycle - 1 >= g_env.map.nb_cycles))
		{
			++g_env.map.nb_cycles;
			l_do_actions();
			if (!--g_env.map.cycle_to_die)
				vm_check_conditions();
		}
		if (g_env.cmd & NCURSE && g_env.dump_cycle <= g_env.map.nb_cycles)
			nc_show();
		else if (g_env.dump_cycle == g_env.map.nb_cycles)
		{
			vm_dump_mem(g_env.map.str, MEM_SIZE);
			nc_std_conf();
		}
	}
}
