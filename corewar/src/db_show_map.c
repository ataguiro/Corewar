/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_show_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 20:05:53 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/10 20:51:34 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	db_show_map(void)
{
	char	*str;
	size_t	i;

	str = g_env.map.str;
	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%.2hhx ", str[i]);
		++i;
		if (!(i % 64))
			ft_putchar('\n');
	}
}
