/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_get_opt_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:41:17 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/26 17:22:17 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_get_opt_player(char **av, int *i)
{
	(*i)++;
	g_env.cmd ^= NB_PLAY;
	if (!ft_is_digit_str(av[*i]))
	{
		vm_usage();
		exit(EXIT_FAILURE);
	}
	else
		g_env.option_nb_play = ft_atoi(av[*i]);
}
