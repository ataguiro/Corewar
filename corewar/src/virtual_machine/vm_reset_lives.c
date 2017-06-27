/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_reset_lives.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 15:37:09 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/06/27 15:47:23 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    vm_reset_lives(void)
{
    t_player *tmp;

    tmp = g_env.player;
    while (tmp)
    {
        tmp->total_live = 0;
        tmp = tmp->next;
    }
}