/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_lst_rm_blk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 14:18:13 by folkowic          #+#    #+#             */
/*   Updated: 2017/06/04 16:38:54 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	nc_lst_rm_blk(t_blink **lst, size_t len)
{
	t_blink	*tmp;

	tmp = (*lst)->next;
	if ((*lst)->prev)
		(*lst)->prev->next = (*lst)->next;
	if ((*lst)->next)
		(*lst)->next->prev = (*lst)->prev;
	nc_refresh_color((*lst)->pos, len);
	free(*lst);
	*lst = tmp;
}