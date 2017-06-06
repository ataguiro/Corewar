/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_get_dump.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:41:02 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/26 17:18:47 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_get_dump(char **av, int *i)
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
