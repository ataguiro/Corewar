/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_lst_add_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:53:40 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/20 17:08:11 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_lst_add_player(t_player **lst, t_player *n)
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
