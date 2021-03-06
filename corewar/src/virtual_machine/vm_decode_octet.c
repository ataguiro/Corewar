/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_decode_octet.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <sle-lieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:16:11 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/26 17:16:34 by sle-lieg         ###   ########.fr       */
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

t_decode				*vm_decode_octet(unsigned char oct, unsigned char cut)
{
	static t_decode dec;

	dec.param1 = l_len(oct >> 6);
	dec.param2 = l_len((oct & 0x3f) >> 4);
	dec.param3 = l_len((oct & 0x0f) >> 2);
	if (cut)
	{
		dec.param1 == 4 ? dec.param1 = 2 : 0;
		dec.param2 == 4 ? dec.param2 = 2 : 0;
		dec.param3 == 4 ? dec.param3 = 2 : 0;
	}
	return (&dec);
}
