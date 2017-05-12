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

static void	l_print_classic(unsigned char player, char c, char *tab)
{
	(void)tab;
	if (player == '1')
		ft_strcat(tab, GREEN);
	else if (player == '2')
		ft_strcat(tab, BLUE);
	else if (player == '3')
		ft_strcat(tab, RED);
	else if (player == '4')
		ft_strcat(tab, CYAN);
	else
		ft_strcat(tab, GREY);
	ft_strcat(tab, l_hex(c));
	ft_strcat(tab, DEFAULT);
	ft_strcat(tab, " ");
}

static void	l_print_cursor(unsigned char player, char c, char *tab)
{
	(void)tab;
	if (player == '1')
		ft_strcat(tab, GREEN_CURSOR);
	else if (player == '2')
		ft_strcat(tab, BLUE_CURSOR);
	else if (player == '3')
		ft_strcat(tab, RED_CURSOR);
	else if (player == '4')
		ft_strcat(tab, CYAN_CURSOR);
	else
		ft_strcat(tab, GREY_CURSOR);
	ft_strcat(tab, l_hex(c));
	ft_strcat(tab, DEFAULT);
	ft_strcat(tab, " ");
}

static unsigned char	l_cmp_cursor(t_player *player, size_t target)
{
	t_player		*tmp;
	unsigned char	num_player;

	num_player = '1';
	tmp = player;
	while (player)
	{
		if (player->cursor == target)
			return (num_player);
		++num_player;
		player = player->next;
	}
	return (0);
}

void	db_show_map(void)
{
	static char			tab[MEM_SIZE * 20] = {'\0'};
	unsigned char	*str;
	unsigned char	*player;
	unsigned char	cursor;
	size_t			i;

	ft_bzero(tab, MEM_SIZE * 20);
	str = g_env.map.str;
	player = g_env.map.player;
	i = 0;
	tab[0] = '\0';
	while (i < MEM_SIZE)
	{
		if ((cursor = l_cmp_cursor(g_env.player, i)))
			l_print_cursor(cursor, str[i], tab);
		else
			l_print_classic(player[i], str[i], tab);
		++i;
		if (!(i % 64))
			ft_strcat(tab, "\n");
	}
	ft_putstr("\033[H\033[2J");
	ft_putstr(tab);
}
