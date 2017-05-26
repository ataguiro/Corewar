/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_lst_add_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 16:55:25 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/20 19:06:03 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void 	vm_lst_add_process(t_process **lst, t_process *n)
{
	if (!lst)
		exit(EXIT_FAILURE);
	if (!*lst)
		*lst = n;
	else
	{
		n->next = *lst;
		(*lst)->prev = n;
		*lst = n;
	}
}
