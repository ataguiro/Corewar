/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:51:29 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/26 17:17:50 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_get_arg(t_decode *args, size_t *curs)
{
	args->arg1 = vm_get_param_val(*curs, args->param1);
	*curs = (*curs + args->param1) % MEM_SIZE;
	args->arg2 = vm_get_param_val(*curs, args->param2);
	*curs = (*curs + args->param2) % MEM_SIZE;
	args->arg3 = vm_get_param_val(*curs, args->param3);
	*curs = (*curs + args->param3) % MEM_SIZE;
	args->arg1 = args->param1 == 2 ? (short)args->arg1 : args->arg1;
	args->arg2 = args->param2 == 2 ? (short)args->arg2 : args->arg2;
	args->arg3 = args->param3 == 2 ? (short)args->arg3 : args->arg3;
}
