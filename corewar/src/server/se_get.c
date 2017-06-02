/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 00:03:45 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/02 02:19:56 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	fill_opt(char **av, int ac)
{
	int	i;

	i = -1;
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