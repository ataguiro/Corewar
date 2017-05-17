/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_color_area.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 18:34:22 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/17 18:54:27 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_color_area(size_t target, size_t len, int num_player)
{
	while (len--)
		g_env.map.player[(target + len) % MEM_SIZE] = num_player;
}
