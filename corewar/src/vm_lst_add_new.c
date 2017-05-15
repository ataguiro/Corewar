/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_lst_add_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 13:57:54 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/15 14:16:17 by folkowic         ###   ########.fr       */
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

void	vm_lst_add_cpy(t_player **lst)
{
	t_player	*cpy;

	cpy = l_lst_cpy(*lst);
	if (lst)
	{
		if (!*lst)
			*lst = cpy;
		else
		{
			cpy->prev = *lst;
			cpy->next = (*lst)->next;
			(*lst)->next = cpy;
			if (cpy->next)
				cpy->next->prev = cpy;
		}
	}
}
