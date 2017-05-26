/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_get_nbplayer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:36:08 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/26 12:17:43 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static bool	nb_is_free(int nb_to_check)
{
	// t_player *tmp;

	// tmp = g_env.player;
	// while (tmp)
	// {
	// 	if (tmp->number == nb_to_check)
	// 		return (0);
	// 	tmp = tmp->next;
	// }
	size_t	i;

	i = 0;

	while (++i < NB_PLAY)
		if (g_env.num_player[i] == nb_to_check)
			return (false);
	return (true);
}

void 		vm_get_nbplayer(void)
{
	static int	nb_player = -1;
	static int	i = 1;

	//a modifier pour ne pas avoir de doublon de joueur ? bien que ca peut
	//un mode double player ?
	if (g_env.cmd & NB_PLAY)
	{
		g_env.num_player[i++] = g_env.option_nb_play;
		g_env.cmd ^= NB_PLAY;
	}
	else
	{
		while (!nb_is_free(nb_player))
			--nb_player;
		g_env.num_player[i++] = nb_player--;
	}
	g_env.map.nb_process = i - 1;
}
