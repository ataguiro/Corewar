/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 23:37:04 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/04 03:52:21 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "server.h"

void	se_check(char **ev)
{
	int		i;
	char	*tmp;
	char	*sector;

	i = -1;
	sector = NULL;
	if (!ev)
		return ;
	while (ev[++i])
	{
		tmp = ft_strdup(ev[i]);
		sector = ft_strchr(tmp, '=');
		if (sector)
			*sector = 0;
		if (!ft_strcmp(tmp, "SE_COREWAR"))
		{
			signal(SIGINT, se_handle);
			g_server.server_mode = ON;
			g_server.num_players = ft_atoi(sector + 1);
			break ;
		}
		free(tmp);
	}
	return ;
}