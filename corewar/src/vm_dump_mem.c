/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_dumb_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:41:18 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/26 17:16:56 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline char	*ft_conv_hex(unsigned char addr)
{
	static char		c[2];

	c[0] = addr >> 4;
	if (c[0] > 9)
		c[0] += 'a' - 10;
	else
		c[0] += '0';
	c[1] = addr & 0x0F;
	if (c[1] > 9)
		c[1] += 'a' - 10;
	else
		c[1] += '0';
	return (c);
}

static inline void	print_hex(char *str, unsigned char *addr,
		size_t size)
{
	static char		*c;
	size_t			i;
	size_t			j;

	j = 0;
	i = 0;
	while (i < size)
	{
		c = ft_conv_hex(addr[i]);
		str[(j)++] = c[0];
		str[(j)++] = c[1];
		++i;
		str[(j)++] = ' ';
	}
}

void				vm_dump_mem(const void *addr, size_t size)
{
	static char		str[96] = {'\0'};
	size_t			i;
	size_t			l;

	l = 32;
	i = 0;
	while (addr && i < size)
	{
		if (i + 32 > size)
			l = size - i;
		print_hex(str, (unsigned char *)addr + i, l);
		if (i % 32 == 0)
		{
			str[95] = '\n';
			write(1, str, 96);
		}
		i += l;
	}
}
