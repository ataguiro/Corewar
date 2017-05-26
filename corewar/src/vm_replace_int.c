/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_replace_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:22:08 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/26 17:31:23 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_replace_int(size_t offset, unsigned int val)
{
	*(g_env.map.str + (offset % MEM_SIZE)) = val >> 24;
	*(g_env.map.str + ((offset + 1) % MEM_SIZE)) = val << 8 >> 24;
	*(g_env.map.str + ((offset + 2) % MEM_SIZE)) = val << 16 >> 24;
	*(g_env.map.str + ((offset + 3) % MEM_SIZE)) = val << 24 >> 24;
}
