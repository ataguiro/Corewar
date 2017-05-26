/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 16:06:49 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/09 18:48:54 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		size_t size, size_t *j)
{
	static char		*c;
	size_t			i;

	*j = 0;
	i = 0;
	while (i < size)
	{
		c = ft_conv_hex(addr[i]);
		str[(*j)++] = c[0];
		str[(*j)++] = c[1];
		++i;
		if (i % 2 == 0)
			str[(*j)++] = ' ';
	}
	while (i < 16)
	{
		str[(*j)++] = ' ';
		str[(*j)++] = ' ';
		if (i % 2)
			str[(*j)++] = ' ';
		++i;
	}
}

static inline void	print_char(char *str, unsigned char *addr,
		size_t size, size_t *j)
{
	unsigned char	c;
	size_t			i;

	i = 0;
	while (i < size)
	{
		c = addr[i];
		if (c >= 32 && c <= 126)
			str[(*j)++] = c;
		else
			str[(*j)++] = '.';
		++i;
	}
	while (*j < LEN)
		str[(*j)++] = '\0';
}

void				ft_print_memory(const void *addr, size_t size)
{
	static char		str[LEN] = {'\0'};
	size_t			i;
	size_t			l;
	size_t			j;

	l = 16;
	i = 0;
	while (addr && i < size)
	{
		if (i + 16 > size)
			l = size - i;
		print_hex(str, (unsigned char *)addr + i, l, &j);
		print_char(str, (unsigned char *)addr + i, l, &j);
		if (i % 16 == 0)
		{
			str[LEN - 1] = '\n';
			write(1, str, LEN);
		}
		i += l;
	}
}