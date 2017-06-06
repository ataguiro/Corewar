/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_fill_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 11:16:21 by folkowic          #+#    #+#             */
/*   Updated: 2017/06/06 18:15:58 by folkowic         ###   ########.fr       */
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
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		str = l_memjoin(&str, buf, header->prog_size, ret);
		header->prog_size += ret;
	}
	fd ? close(fd) : 0;
	return (str);
}

static void	l_get_option(char **av, int *i)
{
	if (!ft_strcmp(av[*i], "-dump"))
		vm_get_dump(av, i);
	else if (av[*i][1] == 'n' && !av[*i][2])
		vm_get_opt_player(av, i);
	else if (av[*i][1] == 's' && !av[*i][2])
		g_env.cmd ^= NCURSE;
	else
		vm_usage();
}

void		vm_fill_player(int argc, char **argv)
{
	int		i;

	vm_check_length(argc, argv);
	i = 0;
	while (++i < argc)
	{
		if (*argv[i] == '-')
			l_get_option(argv, &i);
		else
		{
			vm_lst_add_player(&g_env.player, vm_lst_new_player());
			vm_lst_add_process(&g_env.process, vm_lst_new_process());
			g_env.player->str = l_fill_buff(argv[i], &g_env.player->header);
			g_env.player->header = vm_get_player(g_env.player->str);
			vm_get_nbplayer();
		}
	}
}
