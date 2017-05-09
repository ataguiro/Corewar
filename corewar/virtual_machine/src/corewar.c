/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:23:23 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/09 20:55:04 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static char	*vm_memjoin(char *s1, char *s2, size_t len_s1, size_t len_s2)
{
	char	*str;

	if (!(str = malloc(sizeof(*str) * (len_s1 + len_s2))))
		exit(EXIT_FAILURE);
	ft_memcpy(str, s1, len_s1);
	ft_memcpy(str + len_s1, s2, len_s2);
	return (str);
}

static char	*vm_fill_buff(char *path, t_header *header)
{
	char	*str;
	char	*tmp;
	int		ret;
	int		fd;
	char	buf[BUF_SIZE + 1];

	str = NULL;
	tmp = NULL;
	if ((fd = open(path, O_RDONLY)) < 0)
		perror("");
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		tmp = str;
		str = vm_memjoin(str, buf, header->prog_size, ret);
//		free(tmp);
		header->prog_size += ret;
	}
	ft_strdel(&tmp);
	return (str);
}

static void	vm_dcl_player(int argc, char **argv)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		vm_lst_add(&g_env.player, vm_lst_new());
		g_env.player->str = vm_fill_buff(argv[i], &g_env.player->header);
	}
}

int		main(int argc, char **argv)
{
	vm_dcl_player(argc, argv);
	t_player *player2;
	for (t_player *player = g_env.player ; player ; player = player->next)
	{
		ft_print_memory(player->str, player->header.prog_size);
		if (!player->next)
			player2 = player;
	}
	ft_printf("\n");
	for ( ; player2 ; player2 = player2->prev)
	{
		ft_print_memory(player2->str, player2->header.prog_size);
	}
	return (0);
}
