/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_generate_show.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:53:40 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/24 14:31:07 by folkowic         ###   ########.fr       */
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

static void	l_init_map(void)
{
	move(TOP_GAME ,LEFT_GAME);
	(void)l_hex;
	printw("%s", g_env.map.str);
	printw("test");
}

void		nc_generate_show(void)
{
	l_init_map();
	refresh();
}
