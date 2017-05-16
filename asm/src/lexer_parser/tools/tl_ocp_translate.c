/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_ocp_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:25:04 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/16 12:03:22 by ataguiro         ###   ########.fr       */
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
		return (1);
	return (0);
}

static void	correct_index(int *result, int j)
{
	int	i;

	i = -1;
	if (two_byte(g_optab[j].ins_name))
	{
		while (++i < 3)
			if (result[i] == 4)
				result[i] = 2;
	}
}

static int	code_to_byte(int code)
{
	if (code == DIR_CODE)
		return (DIR_SIZE);
	if (code == REG_CODE)
		return (REG_SIZE);
	if (code == IND_CODE)
		return (IND_CODE);
	return (0);
}

int			*tl_ocp_translate(char ocp, int j)
{
	static int	result[3];
	int			tmp;

	tmp = 0;
	ft_memset(result, 0, 3);
	tmp = (unsigned char)ocp >> 6;
	result[0] = code_to_byte(tmp);
	tmp = ((unsigned char)ocp & (unsigned char)0b00110000) >> 4;
	result[1] = code_to_byte(tmp);
	tmp = ((unsigned char)ocp & (unsigned char)0b00001100) >> 2;
	result[2] = code_to_byte(tmp);
	correct_index(result, j);
	return (result);
}
