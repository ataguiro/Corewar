/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_show_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:11:58 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/20 17:49:36 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
		ft_printf("\n");
		ft_printf("numero du joueur-> %d\n", tmp->number);
		// ft_printf("PC-> %llu\n", tmp->pc);

		if ((tmp = tmp->next))
			ft_putendl("\n");
	}
}
