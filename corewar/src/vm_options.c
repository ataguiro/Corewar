/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:13:23 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/05/13 17:13:25 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void 	get_dump(char **av, int *i)
{
		(*i)++;
		g_env.cmd ^= DUMP;
		if (!ft_is_digit_str(av[*i]))
		{
			vm_usage();
			exit(EXIT_FAILURE);
		}
		g_env.dump_cycle = ft_atoi(av[*i]);	
}

void 	get_nbplayer(char **av, int *i)
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