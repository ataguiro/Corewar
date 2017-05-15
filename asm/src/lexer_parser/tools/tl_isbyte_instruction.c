/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_isbyte_instruction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:15:12 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/15 10:20:42 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	tl_isbyte_instruction(int subject)
{
	int	i;

	i = -1;
	while (++i < REG_NUMBER)
		if (g_optab[i].opcode == subject)
			return (1);
	return (0);
}
