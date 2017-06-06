/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_accept_players.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 00:21:34 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/06 15:20:47 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int			g_saver = 0;
int			g_len = 0;
t_client	g_client[5];
pthread_t	accept_mode = 0;

static void		init_structure(void)
{
	int	i;

	i = -1;
	ft_bzero((char *)&g_server.s.s_addr, sizeof(g_server.s.s_addr));
	g_server.s.port = 4243;
	g_server.s.s_addr.sin_family = AF_INET;
	g_server.s.s_addr.sin_port = htons(g_server.s.port);
	while (++i < 5)
	{
		g_client[i].connected = 0;
		g_client[i].ready = 0;
		g_client[i].id = 0;
		g_client[i].cli = 0;
	}
}

static int		check_clients(void)
{
	int	i;

	i = -1;
	while (++i < g_server.num_players)
	{
		if (!g_client[i].ready)
			return (0);
	}
	return (1);
}

void			se_accept_players(void)
{
	int			i;

	i = 0;
	g_len = ft_tablen(g_server.se_av);
	se_secure((g_server.s.sfd = socket(AF_INET, SOCK_STREAM, 0)));
	init_structure();
	se_secure((bind(g_server.s.sfd, (struct sockaddr *)&g_server.s.s_addr, \
		sizeof(g_server.s.s_addr))));
	se_secure((listen(g_server.s.sfd, 5)));
	if (pthread_create(&accept_mode, NULL, se_accept_thread, NULL))
		se_fatal();
	while (!g_server.ready)
	{
		if(check_clients())
		{
			pthread_cancel(accept_mode);
			break ;
		}
	}
}
