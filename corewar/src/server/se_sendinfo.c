/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_sendinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 14:49:37 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/04 03:09:29 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	se_sendinfo(int i)
{
	int	j;

	j = -1;
	g_client[i].connected = 1;
	ft_dprintf(g_client[i].fd, "%d\n", g_server.num_players);
	ft_dprintf(g_client[i].fd, "%d\n", i);
	while (++j < 4)
	{
		ft_dprintf(g_client[i].fd, "%s\n", g_client[j].ready ? "yes" : "no");
		ft_dprintf(g_client[i].fd, "%s\n", g_client[j].connected ? "yes" : "no");
		ft_dprintf(g_client[i].fd, "%d\n", g_client[j].id);
		ft_dprintf(g_client[i].fd, "%d\n", j);
	}
}