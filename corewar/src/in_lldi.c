/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:36:55 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/21 15:09:36 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_decode		*l_valid_lldi(t_process *proc)
{
	unsigned char 	ocp;
	t_decode 		*args;

	ocp = g_env.map.str[(proc->pc + 1) % MEM_SIZE];
	args = vm_decode_octet(ocp, true);
	proc->pc = (proc->pc + args->param1 + args->param2 +
							args->param3 + 2) % MEM_SIZE;
	if ((ocp & 0x30) == 0x30 || (ocp & 0x8) == 0x8 || (ocp & 0xc) == 0xc)
		return (NULL);
	return (args);
}

static bool			l_lldi_args(t_process *proc, t_decode *args)
{
	if (args->param1 == 1 )
	{
		if (args->arg1 < 1 || args->arg1 > 16)
			return (false);
		args->arg1 = proc->reg[args->arg1];
	}
	if (args->param2 == 1)
	{
		if (args->arg2 < 1 || args->arg2 > 16)
			return (false);
		args->arg2 = proc->reg[args->arg2];
	}
	if (args->arg3 < 1 || args->arg3 > 16)
		return (false);
	return (true);
}


void				in_lldi(t_process *proc)
{
	t_decode *args;
	size_t	curs;

	curs = (proc->pc + 2) % MEM_SIZE;
	if (!(args = l_valid_lldi(proc)))
		return ;
	else
	{
		vm_get_arg(args, &curs, true);
		if (!l_lldi_args(proc, args))
			return ;
		else if ((g_env.map.str[(proc->pc + 1) % MEM_SIZE] & 0xC0) == 0xC0)
			args->arg1 = vm_get_param_val(proc->pc + (args->arg1 % IDX_MOD), 4);
		proc->reg[args->arg3] = vm_get_param_val(proc->pc +
			args->arg1  + args->arg2, 4);
		proc->carry = proc->reg[args->arg3] ? false : true;
	}
}

// void in_lldi(t_player *player)
// {
// 	t_decode *args;
// 	size_t	curs;

// 	curs = (player->pc + 1) % MEM_SIZE;
// 	args = vm_decode_octet(g_env.map.str[curs++]);
// 	args->param1 == 4 ? args->param1 = 2 : 0;
// 	args->param2 == 4 ? args->param2 = 2 : 0;
// 	vm_get_arg(args, &curs);
// 	args->arg1 = (short)args->arg1;
// 	args->arg2 = (short)args->arg2;
// 	if (args->param1 == 1 && args->arg1 > 0 && args->arg1 < 17)
// 		args->arg1 = player->reg[args->arg1];
// 	else if ((g_env.map.str[(player->pc + 1) % MEM_SIZE] & 0xC0) == 0xC0)
// 		args->arg1 = vm_get_param_val(player->pc + (args->arg1 % IDX_MOD), 4);
// 	if (args->param2 == 1 && args->arg2 > 0 && args->arg2 < 17)
// 		args->arg2 = player->reg[args->arg2];
// 	if (args->param1 && args->param2 && args->param3 &&
// 						args->arg3 > 0 && args->arg3 < 17)
// 	{
// 		player->reg[args->arg3] = vm_get_param_val(player->pc +
// 		args->arg1  + args->arg2, 4);
// 		player->carry = player->reg[args->arg3] ? false : true;
// 	}
// 	player->pc = curs % MEM_SIZE;
// }
