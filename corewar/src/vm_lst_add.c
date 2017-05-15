/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_lst_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:53:40 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/15 18:46:36 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_lst_add(t_player **lst, t_player *n)
{
	n = vm_lst_new();
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
