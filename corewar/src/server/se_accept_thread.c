/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_accept_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 03:31:15 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/04 03:34:09 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void		save_arg(int i)
{
	g_server.se_av[g_len + i] = ft_strdup(g_client[i].buff);
	g_client[i].id = g_client[i].c_addr.sin_port;
	g_client[i].ready = 1;
}

static void		reset_config(int i)
{
	close(g_client[i].fd);
	g_client[i].connected = 0;
	g_client[i].ready = 0;
	g_client[i].id = 0;
	g_client[i].cli = 0;
}

static void*	client_thread(void *arg)
{
	int	i;
	int	loaded;

	(void)arg;
	i = g_saver;
	loaded = 0;
	if (i == g_server.num_players)
	{
		ft_dprintf(g_client[i].fd, "full\n");
		pthread_exit(NULL);
	}
	while (1)
	{
		se_sendinfo(i);
		ft_bzero(g_client[i].buff, MED);
		read(g_client[i].fd, g_client[i].buff, 255);
		if (!ft_strcmp(g_client[i].buff, "end"))
		{
			reset_config(i);
			pthread_exit(NULL);
		}
		ft_strcmp(g_client[i].buff, "blank") && !loaded ? save_arg(i) : 0;
		ft_strcmp(g_client[i].buff, "blank") ? loaded = 1 : 0;
	}
	pthread_exit(NULL);
}

void			*se_accept_thread(void *arg)
{
	int	i;

	i = 0;
	(void)arg;
	while (1)
	{
		g_client[i].size_c = sizeof(g_client[i].c_addr);
		se_secure((g_client[i].fd = accept(g_server.s.sfd, \
			(struct sockaddr *)&g_client[i].c_addr, &g_client[i].size_c)));
		g_saver = i;
		if (pthread_create(&g_client[i].cli, NULL, client_thread, NULL))
			se_fatal();
		i = se_search_slot();
	}
}