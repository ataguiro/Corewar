/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_decode_octet.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:16:11 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/15 11:07:45 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static unsigned char	l_len(unsigned char p)
{
	if (p == 0x1)
		return (1);
	else if (p == 0x2)
		return (4);
	else if (p == 0x3)
		return (2);
	return (0);
}

t_decode 	*vm_decode_octet(unsigned char oct)
{
	static t_decode dec;

	dec.param1 = l_len(dec.param1 = oct >> 6);
	dec.param2 = l_len((oct & 0x3f) >> 4);
	dec.param3 = l_len((oct & 0x0f) >> 2);
	dec.param4 = l_len(oct & 0x03);
	return(&dec);
}
