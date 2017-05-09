/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_lst_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:53:40 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/09 20:37:11 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void	vm_lst_add(t_player **lst, t_player *n)
{
//	t_player	*tmp;

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
/*	if (lst)
	{
		if (!*lst)
			*lst = n;
		else
		{
			tmp = *lst;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = n;
			n->prev = tmp;
		}
	}*/
}
