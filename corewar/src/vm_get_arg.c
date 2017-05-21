/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:51:29 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/21 19:05:43 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_get_arg(t_decode *args, size_t *curs, bool cut)
{
	args->arg1 = vm_get_param_val(*curs, args->param1);
	*curs = (*curs + args->param1) % MEM_SIZE;
	args->arg2 = vm_get_param_val(*curs, args->param2);
	*curs = (*curs + args->param2) % MEM_SIZE;
	args->arg3 = vm_get_param_val(*curs, args->param3);
	*curs = (*curs + args->param3) % MEM_SIZE;

	// args->arg1 = (cut | args->param1 == 2) ? (short)args->arg1 : args->arg1;
	// args->arg2 = (cut | args->param2 == 2) ? (short)args->arg2 : args->arg2;
	// args->arg3 = (cut | args->param3 == 2) ? (short)args->arg3 : args->arg3;


	// A TESTER SANS CUT !
	(void)cut;
	args->arg1 = args->param1 == 2 ? (short)args->arg1 : args->arg1;
	args->arg2 = args->param2 == 2 ? (short)args->arg2 : args->arg2;
	args->arg3 = args->param3 == 2 ? (short)args->arg3 : args->arg3;

	// if (cut)
	// {
	// 	args->arg1 = (short)args->arg1;
	// 	args->arg2 = (short)args->arg2;
	// 	args->arg3 = (short)args->arg3;
	// }
}
