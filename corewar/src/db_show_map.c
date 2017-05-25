/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_show_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 20:05:53 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/24 22:39:42 by folkowic         ###   ########.fr       */
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

static void	l_memcpy_color(char *tab, char *color, size_t len)
{
	ft_memcpy(tab + g_env.idx, color, len);
	g_env.idx += len;
}

static void	l_print_classic(char process, char c, char *tab)
{
	if (process == 0)
		l_memcpy_color(tab, GREY, 7);
	else if (process == g_env.num_player[1])
		l_memcpy_color(tab, GREEN, 5);
	else if (process == g_env.num_player[2])
		l_memcpy_color(tab, YELLOW, 5);
	else if (process == g_env.num_player[3])
		l_memcpy_color(tab, RED, 5);
	else if (process == g_env.num_player[4])
		l_memcpy_color(tab, CYAN, 5);
	else if (process == 42) //debug
		l_memcpy_color(tab, CYAN, 5);
	ft_strcpy(tab + g_env.idx, l_hex(c));
	g_env.idx += 2;
	l_memcpy_color(tab, DEFAULT, 4);
	ft_strcpy(tab + g_env.idx++, " ");
}

static void	l_print_cursor(char process, char c, char *tab)
{
	if (process == 0)
		l_memcpy_color(tab, GREY_CURSOR, 8);
	else if (process == g_env.num_player[1])
		l_memcpy_color(tab, GREEN_CURSOR, 7);
	else if (process == g_env.num_player[2])
		l_memcpy_color(tab, YELLOW_CURSOR, 7);
	else if (process == g_env.num_player[3])
		l_memcpy_color(tab, RED_CURSOR, 7);
	else if (process == g_env.num_player[4])
		l_memcpy_color(tab, CYAN_CURSOR, 7);
	else if (process == 42) // debug
		l_memcpy_color(tab, CYAN_CURSOR, 5);
	ft_strcpy(tab + g_env.idx, l_hex(c));
	g_env.idx += 2;
	l_memcpy_color(tab, DEFAULT, 4);
	ft_strcpy(tab + g_env.idx++, " ");
}

static int	l_cmp_cursor(t_process *process, size_t target,
		unsigned char *str, char *tab)
{
	t_process		*tmp;

	tmp = process;
	while (process)
	{
		if (process->pc == target)
		{
			l_print_cursor(g_env.map.player[target], str[target], tab);
			return (true);
		}
		process = process->next;
	}
	return (false);
}

char					*db_show_map(void)
{
	static char			tab[MEM_SIZE * 20 + 1] = {'\0'};
	unsigned char	*str;
	int				*player;
	size_t			i;

	g_env.idx = 0;
	str = g_env.map.str;
	player = g_env.map.player;
	i = 0;
	while (i < MEM_SIZE)
	{
		if (!(l_cmp_cursor(g_env.process, i, str, tab)))
			l_print_classic(player[i], str[i], tab);
		++i;
		if (!(i % 64))
			ft_strcpy(tab + g_env.idx++, "\n");
	}
	tab[g_env.idx++] = '\n';
	ft_putstr("\033[H\033[2J");
	// ft_printf("CYCLE TO DIE %d\n", g_env.map.cycle_to_die);
	// ft_printf("CYCLE EN COURS %zu\n", g_env.map.nb_cycles);
 // 	ft_printf("nb process %d\n", g_env.map.nb_process);
	// write(1, tab, g_env.idx);
	getchar();
	return (tab);
}
