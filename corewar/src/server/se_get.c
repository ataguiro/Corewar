/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 00:03:45 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/04 04:20:10 by echo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	fill_opt(char **av, int ac)
{
	int	i;

	i = 0;
	g_server.se_av[i] = ft_strdup(av[i]);
	while (++i < ac)
		if (!(av[i][0] ^ '-'))
			g_server.se_av[i] = ft_strdup(av[i]);
}

void		se_get(char **av, int ac)
{
	if (!av)
		return ;
	if (g_server.server_mode == ON)
	{
		g_server.se_av = (char **)ft_memalloc(sizeof(char *) * (ac + 4));
		fill_opt(av, ac);
		se_accept_players();
	}
}
