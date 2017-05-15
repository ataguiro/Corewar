/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 17:35:41 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/15 16:30:05 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		vm_get_param_val(size_t pos, size_t len)
{
	int			res;
	size_t		offset;

	offset = 0;
	res = 0;
	while (len--)
	{
		res <<= 8;
		res |= g_env.map.str[(pos + offset++) % MEM_SIZE] & 0xFF;
	}
	return (res);
}
