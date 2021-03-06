/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_bigendian.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 10:10:23 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/17 19:05:41 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define MASK 0xFF

/*
**	Converts little endian number to big endian and stores the result as int
*/

int	tl_bigendian(unsigned int num)
{
	int	result;
	int	tmp[4];

	tmp[0] = (num & MASK) << 24;
	tmp[1] = (num & (MASK << 8)) << 8;
	tmp[2] = (num & (MASK << 16)) >> 8;
	tmp[3] = (num & (MASK << 24)) >> 24;
	result = tmp[0] | tmp[1] | tmp[2] | tmp[3];
	return (result);
}
