/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_no_excl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 12:38:54 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/17 16:39:11 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	write_no_excl(int fd, int i, int flag)
{
	int	ret;
	int	*par_size;

	ret = 2;
	par_size = tl_ocp_translate((char)g_load[i + 1], flag);
	write(fd, &g_load[i + 1], 1);
	while (ret < g_optab[flag].max_arg + 2)
	{
		if (par_size[ret - 2] == DIR_SIZE)
			g_load[i + ret] = tl_bigendian(g_load[i + ret]);
		write(fd, &g_load[i + ret], par_size[ret - 2]);
		ret++;
	}
	return (ret);
}
