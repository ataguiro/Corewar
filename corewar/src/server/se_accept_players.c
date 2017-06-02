/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_accept_players.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 00:21:34 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/02 03:16:46 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void		init_structure(void)
{
	ft_bzero((char *)&g_server.s.s_addr, sizeof(g_server.s.s_addr));
	g_server.s.port = 4243;
	g_server.s.s_addr.sin_family = AF_INET;
	g_server.s.s_addr.sin_port = htons(g_server.s.port);
}

static void*	client_thread(void *arg)
{
	int	n;
	int	i;
	int	*tmp;

	n = 0;
	tmp = (int *)arg;
	i = *tmp;
	ft_printf("> %d\n", i);
	while (1)
	{
		ft_bzero(g_server.s.buff[i], MED);
		n = read(g_server.s.cfd[i], g_server.s.buff[i], 255);
		n < 0 ? se_fatal() : 0;
		printf ("Message from client : %s from %d\n", g_server.s.buff[i], g_server.s.c_addr[i].sin_port);
		n = write(g_server.s.cfd[i], "OK\n", 3);
		n < 0 ? se_fatal() : 0;
	}
	pthread_exit(NULL);
}

void			se_accept_players(void)
{
	int			i;
	pthread_t	cli[4];

	i = -1;
	g_server.s.sfd = socket(AF_INET, SOCK_STREAM, 0);
	g_server.s.sfd < 0 ? se_fatal() : 0;
	init_structure();
	if ((bind(g_server.s.sfd, (struct sockaddr *)&g_server.s.s_addr, \
		sizeof(g_server.s.s_addr))) < 0)
		se_fatal();
	listen(g_server.s.sfd, 5);
	while (++i < g_server.num_players)
	{
		g_server.s.size_c[i] = sizeof(g_server.s.c_addr[i]);
		g_server.s.cfd[i] = accept(g_server.s.sfd, \
			(struct sockaddr *)&g_server.s.c_addr[i], &g_server.s.size_c[i]);
		g_server.s.cfd[i] < 0 ? se_fatal() : 0;
		ft_printf(">> %d\n", i);
		if (pthread_create(&cli[i], NULL, client_thread, &i))
			se_fatal();
	}
}