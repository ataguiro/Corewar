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
		if (!*lst)
			*lst = cpy;
		else
		{
			if (!(*lst)->next)
				g_env.player_end = cpy;
			cpy->prev = *lst;
			cpy->next = (*lst)->next;
			(*lst)->next = cpy;
			if (cpy->next)
				cpy->next->prev = cpy;
		}
	}
}
