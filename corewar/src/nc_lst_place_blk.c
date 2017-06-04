/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_lst_place_blk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 12:34:56 by folkowic          #+#    #+#             */
/*   Updated: 2017/06/04 15:30:52 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	nc_lst_insert_blk(t_blink **lst, t_blink *n)
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

void	nc_lst_place_blk(size_t pos)
{
	t_blink	*top;

	top = g_env.blink;
	while (g_env.blink)
	{
		if (g_env.blink->pos == pos)
		{
			g_env.blink->cd = BLK_LIVE;
			break ;
		}
		else if (g_env.blink->pos > pos && ((g_env.blink->next && g_env.blink->next->pos < pos) || !g_env.blink->next))
		{
			nc_lst_insert_blk(&g_env.blink, nc_lst_new_blk(pos, 1));
			break ;
		}
		g_env.blink = g_env.blink->next;
	}
	if (!g_env.blink)
	{
		g_env.blink = top;
		nc_lst_add_blk(&g_env.blink, nc_lst_new_blk(pos, 1));
	}
	else
		g_env.blink = top;
}
