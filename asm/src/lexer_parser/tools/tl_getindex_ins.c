/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_getindex_ins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 11:26:51 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/15 11:27:48 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	tl_getindex_ins(char *ins)
{
	int	i;

	i = -1;
	while (++i < REG_NUMBER)
		if (!ft_strcmp(ins, g_optab[i].ins_name))
			return (i);
	return (0);
}
