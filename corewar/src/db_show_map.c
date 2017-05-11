/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_show_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 20:05:53 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/11 14:51:30 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	l_print_classic(unsigned char player, char c, char *tab)
{
	(void)tab;
	if (player == '1')
		ft_printf("%s%.2hhx", GREEN, c);
	else if (player == '2')
		ft_printf("%s%.2hhx", BLUE, c);
	else if (player == '3')
		ft_printf("%s%.2hhx", RED, c);
	else if (player == '4')
		ft_printf("%s%.2hhx", CYAN, c);
	else
		ft_printf("%s%.2hhx", GREY, c);
	ft_putstr(DEFAULT);
	ft_putchar(' ');
}

static void	l_print_cursor(unsigned char player, char c, char *tab)
{
	(void)tab;
	if (player == '1')
		ft_printf("%s%.2hhx", GREEN_CURSOR, c);
	else if (player == '2')
		ft_printf("%s%.2hhx", BLUE_CURSOR, c);
	else if (player == '3')
		ft_printf("%s%.2hhx", RED_CURSOR, c);
	else if (player == '4')
		ft_printf("%s%.2hhx", CYAN_CURSOR, c);
	else
		ft_printf("%s%.2hhx", GREY, c);
	ft_putstr(DEFAULT);
	ft_putchar(' ');
}

void	db_show_map(void)
{
	char			tab[MEM_SIZE * 4];
	unsigned char	*str;
	unsigned char	*player;
	unsigned char	*cursor;
	size_t			i;

	ft_bzero(tab, MEM_SIZE * 4);
	ft_putstr("\033[H\033[2J");
	str = g_env.map.str;
	player = g_env.map.player;
	cursor = g_env.map.cursor;
	i = 0;
	while (i < MEM_SIZE)
	{
		if (cursor[i] == 0)
			l_print_classic(player[i], str[i], tab);
		else
			l_print_cursor(cursor[i], str[i], tab);
		++i;
		if (!(i % 64))
			ft_putchar('\n');
	}
}
