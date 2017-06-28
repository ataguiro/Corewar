/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_reset_lives.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 15:37:09 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/06/28 10:41:16 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_reset_lives(void)
{
	t_player *tmp;

	tmp = g_env.player;
	while (tmp)
	{
		tmp->total_live = 0;
		tmp = tmp->next;
	}
}
