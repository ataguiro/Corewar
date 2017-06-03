/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_lst_add_blk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:49:11 by folkowic          #+#    #+#             */
/*   Updated: 2017/06/02 19:50:11 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	nc_lst_add_blk(t_blink **lst, t_blink *n)
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
