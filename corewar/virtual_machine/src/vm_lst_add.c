/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_lst_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:53:40 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/10 17:27:55 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void	vm_lst_add(t_player **lst, t_player *n)
{
	if (lst)
	{
		if (!*lst)
			*lst = n;
		else
		{
			n->next = *lst;
			(*lst)->prev = n;
			*lst = n;
		}
	}
}
