/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_show_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:11:58 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/10 17:42:28 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void	db_show_lst(t_player *player)
{
	t_player	*tmp;

	tmp = player;
	while (tmp)
	{
		ft_printf("new lst\n");
		ft_printf("%x\n", tmp->header.magic);
		ft_printf("%s\n", tmp->header.prog_name);
		ft_printf("%x\n", tmp->header.prog_size);
		ft_printf("%s\n", tmp->header.comment);
		if ((tmp = tmp->next))
			ft_putendl("\n");
	}
}
