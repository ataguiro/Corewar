/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_show_reg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 20:48:02 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/14 20:53:22 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	db_show_reg(t_player *player)
{
	size_t	i;

	ft_printf("number player %d\n", player->number);
	ft_printf("nb live %u\n", player->nb_live);
	ft_printf("pc %zu\n", player->pc);
	ft_printf("carry %zu\n", player->carry);
	ft_printf("cycles_cd %zu\n", player->cycles_cd);
	i = 0;
	while (++i <= R16)
		ft_printf("reg[%zu] = %x\n", i, player->reg[i]);
}
