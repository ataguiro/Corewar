/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_excl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:29:37 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/17 19:03:26 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	two_byte(char *ins)
{
	if (!ft_strcmp(ins, "st") || !ft_strcmp(ins, "add")
	|| !ft_strcmp(ins, "sub") || !ft_strcmp(ins, "zjmp")
	|| !ft_strcmp(ins, "ldi") || !ft_strcmp(ins, "sti")
	|| !ft_strcmp(ins, "fork") || !ft_strcmp(ins, "lfork")
	|| !ft_strcmp(ins, "lldi"))
		return (DIR_SIZE / 2);
	return (DIR_SIZE);
}

int			write_excl(int fd, int i, int flag)
{
	int	bytes;

	bytes = two_byte(g_optab[flag].ins_name);
	if (bytes == DIR_SIZE)
		g_load[i + 1] = tl_bigendian((unsigned int)g_load[i + 1]);
	else
		g_load[i + 1] = (int)tl_bigendian_short((short)g_load[i + 1]);
	write(fd, &g_load[i + 1], bytes);
	return (2);
}
