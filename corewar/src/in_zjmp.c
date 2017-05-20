/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:36:14 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/20 16:23:36 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	in_zjmp(t_process *process)
{
	size_t	curs;
	int		value;

	curs = (process->pc + 1) % MEM_SIZE;
	value = (short)vm_get_param_val(curs, 2);
	if (process->carry)
		process->pc = (process->pc + (value % IDX_MOD)) % MEM_SIZE;
	else
		process->pc = (process->pc + 3) % MEM_SIZE;
}
