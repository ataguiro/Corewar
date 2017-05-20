/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_byte_code.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 23:01:15 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/20 15:24:25 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	g_load_index = 0;

#include "asm.h"

static int	excluded(char *ins)
{
	if (!ft_strcmp(ins, "live") || !ft_strcmp(ins, "zjmp")
	|| !ft_strcmp(ins, "fork") || !ft_strcmp(ins, "lfork"))
		return (1);
	return (0);
}

static void	load_ocp(char **tokens, int *i)
{
	int		p;
	int		j;
	short	shift;
	char	ocp;

	p = 0;
	ocp = 0;
	shift = 6;
	j = tl_getindex_ins(tokens[0]);
	g_load[(*i)++] = g_optab[j].opcode;
	if (excluded(tokens[0]))
		return ;
	while (tokens[++p])
	{
		if (tl_isdirect(tokens[p]))
			ocp |= (DIR_CODE << shift);
		else if (tl_isregister(tokens[p]))
			ocp |= (REG_CODE << shift);
		else if (tl_isindex(tokens[p]))
			ocp |= (IND_CODE << shift);
		shift -= 2;
	}
	g_load[(*i)++] = ocp;
}

static void	load_params(char **tokens, int *i)
{
	int	p;
	int	j;

	p = 0;
	j = tl_getindex_ins(tokens[0]);
	while (tokens[++p])
	{
		if (tl_isdirect(tokens[p]))
			tl_dir_translate(tokens[p], i);
		else if (tl_isregister(tokens[p]))
			tl_reg_translate(tokens[p], i);
		else if (tl_isindex(tokens[p]))
			tl_ind_translate(tokens[p], i);
	}
}

void	load_byte_code(char **tokens)
{
	static int	load_index = 0;

	if (g_leave || !ft_strcmp(tokens[0], NAME_CMD_STRING)
	|| !ft_strcmp(tokens[0], COMMENT_CMD_STRING))
		return ;
	load_ocp(tokens, &load_index);
	load_params(tokens, &load_index);
	g_load_index = load_index;
}
