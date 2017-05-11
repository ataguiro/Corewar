/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_ctrl_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 18:18:29 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/11 11:01:32 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** function test use logical true for default
*/

static bool	l_ctrl_magic(t_player *player)
{
	if (player->header.magic == COREWAR_EXEC_MAGIC)
		return (false);
	else
	{
		ft_putendl_fd("Not corewar file", 2);
		return (true);
	}
}

static bool	l_ctrl_prog_name(t_player *player)
{
	size_t	len;

	len = ft_strlen(player->header.prog_name);
	if (!len)
	{
		ft_putendl_fd("Missing name", 2);
		return (true);
	}
	else if (len <= PROG_NAME_LENGTH)
		return (false);
	else
	{
		ft_putendl_fd("Lengh name is too hight", 2);
		return (true);
	}
}

static bool	l_ctrl_prog_size(t_player *player)
{
	if (player->header.prog_size <= CHAMP_MAX_SIZE)
		return (false);
	ft_putendl_fd("Lengh program is too hight", 2);
	return (true);
}

static bool	l_ctrl_comment(t_player *player)
{
	size_t	len;

	len = ft_strlen(player->header.prog_name);
	if (len <= PROG_NAME_LENGTH)
		return (false);
	ft_putendl_fd("Lengh comment is too hight", 2);
	return (true);
}

bool		vm_ctrl_player(t_player *player)
{
	t_player	*tmp;

	tmp = player;
	while (tmp)
	{
		if (l_ctrl_magic(player) || l_ctrl_prog_name(player) ||
				l_ctrl_comment(player) || l_ctrl_prog_size(player))
			;
		else
			++g_env.map.nb_player;
		tmp = tmp->next;
	}
	if (g_env.map.nb_player > MAX_PLAYERS)
	{
		ft_putendl_fd("Number of player is too hight !", 2);
		exit(EXIT_FAILURE);
	}
	return (false);
}
