/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 17:35:41 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/14 17:35:42 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int 	vm_get_param_val(t_player *play, size_t len)
{
	int res;

	res = 0;
	while (len)
	{
		res <<= 8;
		res += g_env.map.str[(play->pc + len--) % MEM_SIZE] & 0xFF;
	}
	return (res);
}