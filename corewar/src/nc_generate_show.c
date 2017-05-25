/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_generate_show.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:53:40 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/24 23:00:09 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char	*l_hex(unsigned char n)
{
	static char	ret[2];

	ret[0] = '0';
	ret[1] = '0';
	ret[0] = n >> 4;
	if (ret[0] <= 9)
		ret[0] += '0';
	else
		ret[0] += 'a' - 10;
	ret[1] = n & 0xf;
	if (ret[1] <= 9)
		ret[1] += '0';
	else
		ret[1] += 'a' - 10;
	return (ret);
}

void		nc_generate_show(void)
{
	static char	str[MEM_SIZE * 4];
	size_t		i;
	size_t		count;

	i = 0;
	count = -1;
	while (++count < g_env.player->header.prog_size)
	{
		ft_memcpy(str + i, l_hex((unsigned char)(g_env.map.str[count])), 2);
		str[i + 2] = ' ';
		i += 3;
	}
	wprintw(g_env.win.w_game, "%s", str);
	wrefresh(g_env.win.w_game);
}
