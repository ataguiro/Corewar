/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_lst_new_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 16:52:13 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/21 19:46:24 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_process	*vm_lst_new_process(void)
{
	t_process	*n;

	if (!(n = malloc(sizeof(*n))))
		exit(EXIT_FAILURE);
	n->nb_live = 0;
	n->pc = 0;
	ft_bzero(n->reg, (REG_NUMBER + 1) * 4);
	n->carry = 0;
	n->instr = 0;
	n->cycles_cd = 0;
	n->next = NULL;
	n->prev = NULL;
	return (n);
}
