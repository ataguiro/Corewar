/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_lst_new_blk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:46:29 by folkowic          #+#    #+#             */
/*   Updated: 2017/06/06 14:49:18 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_blink		*nc_lst_new_blk(size_t pos)
{
	t_blink	*n;

	if (!(n = (t_blink *)malloc(sizeof(*n))))
		exit(EXIT_FAILURE);
	n->pos = pos;
	n->cd = BLK_LIVE;
	n->next = NULL;
	n->prev = NULL;
	return (n);
}
