/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_fill_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 11:16:21 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/10 20:25:19 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char	*l_memjoin(char **in, char *buf, size_t len_s1, size_t len_s2)
{
	char	*str;

	if (!(str = malloc(sizeof(*str) * (len_s1 + len_s2))))
		exit(EXIT_FAILURE);
	ft_memcpy(str, *in, len_s1);
	ft_memcpy(str + len_s1, buf, len_s2);
	ft_strdel(in);
	return (str);
}

static char	*l_fill_buff(char *path, t_header *header)
{
	char	*str;
	int		ret;
	int		fd;
	char	buf[BUF_SIZE + 1];

	str = NULL;
	if ((fd = open(path, O_RDONLY)) < 0)
		perror("");
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		str = l_memjoin(&str, buf, header->prog_size, ret);
		header->prog_size += ret;
	}
	fd ? close(fd) : 0;
	return (str);
}

static void vm_get_option(char **av, int *i)
{
	if (!ft_strcmp(av[*i], "-dump"))
		get_dump(av, i);
	else if (av[*i][1] == 'n')
		get_nbplayer(av, i);
}

void 		vm_usage(void)
{
	ft_printf("Usage: [-dump nbr_cycles] [[-n number] champion1.cor] ...\n");
}

void		vm_fill_player(int argc, char **argv)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (*argv[i] == '-')
			vm_get_option(argv, &i);
		else
		{
			vm_lst_add(&g_env.player, vm_lst_new());
			g_env.player->str = l_fill_buff(argv[i], &g_env.player->header);
			g_env.player->header = vm_get_player(g_env.player->str);
			if (g_env.cmd & NB_PLAY)
			{
				g_env.player->number = g_env.option_nb_play;
				g_env.cmd ^= NB_PLAY;	
			}
		}
	}
}