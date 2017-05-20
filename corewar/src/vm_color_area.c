/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_color_area.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 18:34:22 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/20 23:50:19 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_color_area(size_t target, size_t len, int num_player)
{
	if (g_env.map.nb_cycles > 3580)
		num_player = 42;
	while (len--)
		g_env.map.player[(target + len) % MEM_SIZE] = num_player;
}
