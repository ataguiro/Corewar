/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_show_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 20:05:53 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/11 11:24:03 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	db_show_map(void)
{
	unsigned char	*str;
	unsigned char	*player;
	size_t			i;

	str = g_env.map.str;
	player = g_env.map.player;
	i = 0;
	while (i < MEM_SIZE)
	{
		if (player[i] == '1')
			ft_printf("%s%.2hhx ", GREEN, str[i]);
		else if (player[i] == '2')
			ft_printf("%s%.2hhx ", BLUE, str[i]);
		else if (player[i] == '3')
			ft_printf("%s%.2hhx ", RED, str[i]);
		else if (player[i] == '4')
			ft_printf("%s%.2hhx ", CYAN, str[i]);
		else
			ft_printf("%s%.2hhx ", DEFAULT, str[i]);
		++i;
		if (!(i % 64))
			ft_putchar('\n');
	}
}
