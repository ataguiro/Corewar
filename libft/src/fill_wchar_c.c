/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_wchar_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 13:39:05 by ataguiro          #+#    #+#             */
/*   Updated: 2017/02/26 13:53:29 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

#include "ft_printf.h"
#include "tools.h"

static void	even_bigger(char *hex, wint_t rec)
{
	if (rec < 0x10000)
	{
		hex[0] = (rec >> 12) | 0xe0;
		hex[1] = ((rec >> 6) & 0x3f) | 0x80;
		hex[2] = (rec & 0x3f) | 0x80;
	}
	else if (rec < 0x200000)
	{
		hex[0] = (rec >> 18) | 0xf0;
		hex[1] = ((rec >> 12) & 0x3f) | 0x80;
		hex[2] = ((rec >> 6) & 0x3f) | 0x80;
		hex[3] = (rec & 0x3f) | 0x80;
	}
	else if (rec < 0x4000000)
	{
		hex[0] = (rec >> 24) | 0xf8;
		hex[1] = ((rec >> 18) & 0x3f) | 0x80;
		hex[2] = ((rec >> 12) & 0x3f) | 0x80;
		hex[3] = ((rec >> 6) & 0x3f) | 0x80;
		hex[4] = (rec & 0x3f) | 0x80;
	}
}

static void	just_to_be_sure(char *hex, wint_t rec)
{
	if (rec < 0x7fffffff)
	{
		hex[0] = (rec >> 30) | 0xfc;
		hex[1] = ((rec >> 24) & 0x3f) | 0x80;
		hex[2] = ((rec >> 18) & 0x3f) | 0x80;
		hex[3] = ((rec >> 12) & 0x3f) | 0x80;
		hex[4] = ((rec >> 6) & 0x3f) | 0x80;
		hex[5] = (rec & 0x3f) | 0x80;
	}
}

void		fill_wchar_c(wint_t rec, int *j)
{
	char	hex[6];
	int		i;

	ft_memset(hex, 0, 6);
	i = 0;
	if (rec < 0x0080)
		hex[0] = rec;
	else if (rec < 0x800)
	{
		hex[0] = (rec >> 6) | 0xc0;
		hex[1] = (rec & 0x3f) | 0x80;
	}
	else if (rec < 0x10000)
		even_bigger(hex, rec);
	else if (rec < 0x7fffffff && rec >= 0x4000000)
		just_to_be_sure(hex, rec);
	while (hex[i])
		fselect()->final_string[(*j)++] = hex[i++];
}
