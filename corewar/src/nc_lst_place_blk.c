/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_lst_place_blk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 12:34:56 by folkowic          #+#    #+#             */
/*   Updated: 2017/06/04 16:08:29 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	nc_lst_insert_blk(t_blink **lst, t_blink *n)
{
	if (lst)
	{
		if (!*lst)
			*lst = n;
		else
		{
			n->prev = *lst;
			n->next = (*lst)->next;
			if ((*lst))
				(*lst)->next = n;
			if (n->next)
				n->next->prev = n;
		}
	}
}

void		nc_lst_place_blk(t_blink **blink, size_t pos)
{
	t_blink	*top;

	top = *blink;
	while (*blink)
	{
		if ((*blink)->pos == pos)
		{
			(*blink)->cd = BLK_LIVE;
			break ;
		}
		else if ((*blink)->pos > pos && (((*blink)->next &&
				(*blink)->next->pos < pos) || !(*blink)->next))
		{
			nc_lst_insert_blk(blink, nc_lst_new_blk(pos));
			break ;
		}
		*blink = (*blink)->next;
	}
	if (!*blink)
	{
		*blink = top;
		nc_lst_add_blk(blink, nc_lst_new_blk(pos));
	}
	else
		*blink = top;
}
