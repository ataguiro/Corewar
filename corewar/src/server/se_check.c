/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 23:37:04 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/02 02:43:49 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "server.h"

void	se_check(char **ev)
{
	int		i;
	char	*sector;

	i = -1;
	sector = NULL;
	if (!ev)
		return ;
	while (ev[++i])
	{
		sector = ft_strchr(ev[i], '=');
		if (sector)
			*sector = 0;
		if (!ft_strcmp(ev[i], "SE_COREWAR"))
		{
			g_server.server_mode = ON;
			g_server.num_players = ft_atoi(sector + 1);
			break ;
		}
	}
	return ;
}