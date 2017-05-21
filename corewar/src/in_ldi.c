/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:36:22 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/21 20:13:31 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_decode	*l_valid_ldi(t_process *proc)
{
	unsigned char 	ocp;
	t_decode 		*args;

	ocp = g_env.map.str[(proc->pc + 1) % MEM_SIZE];
	args = vm_decode_octet(ocp, true);
	proc->pc = (proc->pc + args->param1 + args->param2 +
							args->param3 + 2) % MEM_SIZE;
	if ((ocp & P2_MSK) == P2_IND || (ocp & P3_MSK) != P3_REG)
		return (NULL);
	return (args);
}

static bool		l_ldi_args(t_process *proc, t_decode *args)
{
	if (args->arg1 == REG_SIZE)
	{
		if (args->arg1 < 1 || args->arg1 > 16)
			return (false);
		args->arg1 = proc->reg[args->arg1];
	}
	if (args->arg2 == REG_SIZE)
	{
		if (args->arg2 < 1 || args->arg2 > 16)
			return (false);
		args->arg2 = proc->reg[args->arg2];
	}
	if (args->arg3 < 1 || args->arg3 > 16)
		return (false);
	return (true);
}

void			in_ldi(t_process *proc)
{
	t_decode	*args;
	size_t		curs;
	size_t		from;

	from = proc->pc;
	curs = (proc->pc + 2) % MEM_SIZE;
	if (!(args = l_valid_ldi(proc)))
		return ;
	vm_get_arg(args, &curs, true);
	ft_printf("================ARG %d - %x==========\n", args->arg1, args->arg1);
	ft_printf("================ARG %d - %x==========\n", args->arg2, args->arg2);
	ft_printf("================ARG %d - %x==========\n", args->arg3, args->arg3);
	if (!l_ldi_args(proc, args))
		return ;
	if ((g_env.map.str[(from + 1) % MEM_SIZE] & P1_MSK) == P1_IND)
		args->arg1 = vm_get_param_val(from + args->arg1, 4);// % IDX_MOD;
	if ((g_env.map.str[(from + 1) % MEM_SIZE] & P2_MSK) == P2_IND)
		args->arg2 = vm_get_param_val(from + args->arg2, 4);// % IDX_MOD;
	proc->reg[args->arg3] = vm_get_param_val
		(from + ((args->arg1 + args->arg2) % IDX_MOD), 4);
}

// void	in_ldi(t_process *process)
// {
// 	t_decode *args;
// 	size_t	curs;
//
// 	curs = (process->pc + 1) % MEM_SIZE;
// 	args = vm_decode_octet(g_env.map.str[curs++], false);
// 	args->param1 == 4 ? args->param1 = 2 : 0;
// 	args->param2 == 4 ? args->param2 = 2 : 0;
// 	vm_get_arg(args, &curs, false);
// 	args->arg1 = (short)args->arg1;
// 	args->arg2 = (short)args->arg2;
// 	if (args->param1 == 1 && args->arg1 > 0 && args->arg1 < 17)
// 		args->arg1 = process->reg[args->arg1];
// 	else if ((g_env.map.str[(process->pc + 1) % MEM_SIZE] & 0xC0) == 0xC0)
// 		args->arg1 = vm_get_param_val(
// 				(process->pc + (args->arg1 % IDX_MOD)) % MEM_SIZE, 4);
// 	if (args->param2 == 1 && args->arg2 > 0 && args->arg2 < 17)
// 		args->arg2 = process->reg[args->arg2];
// 	if (args->param1 && args->param2 && args->param3)
// 	{
// 		if (args->arg3 > 0 && args->arg3 < 17)
// 			process->reg[args->arg3] = vm_get_param_val(process->pc +
// 				((args->arg1 + args->arg2) % IDX_MOD) % MEM_SIZE, 4);
// 		process->pc = curs % MEM_SIZE;
// 	}
// 	else
// 	  process->pc = (process->pc + 2) % MEM_SIZE;
// 	// db_show_reg(process);
// }
