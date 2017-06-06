/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:07:27 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/06 18:18:45 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	close_threads(void)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		ft_dprintf(2, "Closing thread number %d (%d)\n", i, g_client[i].cli);
		pthread_cancel(g_client[i].cli);
	}
}

void		se_handle(int sig)
{
	int	i;

	if (sig == SIGINT)
	{
		i = -1;
		ft_dprintf(2, "\nClosing all threads...\n");
		close_threads();
		ft_dprintf(2, "Disconnecting all clients...\n");
		pthread_cancel(g_accept_mode);
		while (g_client[++i].fd && i < 4)
		{
			close(g_client[i].fd);
			ft_dprintf(2, "Client %d : disconnected\n", g_client[i].fd);
		}
		ft_dprintf(2, "Closing server fd... ");
		close(g_server.s.sfd);
		ft_dprintf(2, "done.\n");
		exit(EXIT_FAILURE);
	}
}
