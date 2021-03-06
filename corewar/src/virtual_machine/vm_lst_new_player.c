/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_lst_new_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:43:00 by folkowic          #+#    #+#             */
/*   Updated: 2017/06/27 15:51:17 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_player	*vm_lst_new_player(void)
{
	t_player	*n;

	if (!(n = malloc(sizeof(*n))))
		exit(EXIT_FAILURE);
	n->header = (t_header){0, {'\0'}, 0, {'\0'}};
	n->last_live = 0;
	n->total_live = 0;
	n->next = NULL;
	n->prev = NULL;
	return (n);
}
