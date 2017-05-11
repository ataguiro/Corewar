/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_decode_octet.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:16:11 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/11 15:16:12 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_decode 	*vm_decode_octet(unsigned char oct)
{
	static t_decode dec;

	dec.param1 = oct >> 6;
	dec.param2 = oct << 2 >> 6;
	dec.param3 = oct << 4 >> 6;
	dec.param4 = oct << 6 >> 6;
	return(&dec)
}