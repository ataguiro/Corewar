/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:37:14 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/21 19:04:52 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_decode *l_valid_aff(t_process *proc)
{
	unsigned char 	ocp;
	t_decode 		*args;

	ocp = g_env.map.str[(proc->pc + 1) % MEM_SIZE];
	args = vm_decode_octet(ocp, false);
	proc->pc = (proc->pc + args->param1 + 2) % MEM_SIZE;
	if ((ocp & P1_MSK) != P1_REG)
		return (NULL);
	return (args);
}

void in_aff(t_process *proc)
{
	t_decode *args;
	size_t	curs;

	curs = (proc->pc + 2) % MEM_SIZE;
	if (!(args = l_valid_aff(proc)))
		return ;
	vm_get_arg(args, &curs);
	if (args->arg1 > 0 && args->arg1 < 17)
		ft_printf("%c", proc->reg[args->arg1] % 256);
}