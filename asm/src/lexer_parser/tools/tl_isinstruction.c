/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_isinstruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 22:37:48 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/09 23:54:52 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	tl_isinstruction(char *subject)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < 17)
		if (!ft_strcmp(g_optab[i].ins_name, subject))
			return (1);
	return (0);
}