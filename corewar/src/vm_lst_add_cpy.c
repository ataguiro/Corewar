/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_lst_add_cpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:15:53 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/15 18:49:53 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_player	*l_lst_cpy(t_player *player)
{
	t_player	*cpy;

	if (!(cpy = malloc(sizeof(*cpy))))
		exit(EXIT_FAILURE);
	ft_memcpy(cpy, player, sizeof(*player));
	cpy->str = ft_strdup(player->str);
	cpy->next = NULL;
	cpy->prev = NULL;
	return (cpy);
}

void			vm_lst_add_cpy(t_player **lst)
{
	t_player	*cpy;

	cpy = l_lst_cpy(*lst);
	if (lst)
	{
		if (!*lst)        	// vraiment utile ??
			*lst = cpy;		// si plus de (*lst), alors partie finie, a verifier
		else
		{
			cpy->next = g_env.player;
			g_env.player->prev = cpy;
			g_env.player = cpy;
		}
	}
}