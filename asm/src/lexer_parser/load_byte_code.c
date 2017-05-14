/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_byte_code.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 23:01:15 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/14 09:53:31 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define DIRECT 0b10
#define INDEX 0b11
#define REGISTRE 0b01
//
// static void	load_ocp(char **tokens, int *i)
// {
// 	int		p;
// 	int		j;
// 	short	shift;
// 	char	ocp;
//
// 	j = -1;
// 	p = 0;
// 	ocp = 0;
// 	shift = 8;
// 	while (++j < REG_NUMBER)
// 		if (!ft_strcmp(tokens[0], g_optab[j].ins_name))
// 			break ;
// 	g_load[(*i)++] = g_optab[j].opcode;
// 	while (tokens[++p])
// 	{
// 		if (tl_isdirect(tokens[p]))
// 			ocp |= (DIRECT << shift);
// 		else if (tl_isregister(tokens[p]))
// 			ocp |= (REGISTRE << shift);
// 		else if (tl_isindex(tokens[p]))
// 			ocp |= (INDEX << shift);
// 		shift -= 2;
// 	}
// 	g_load[(*i)++] = ocp;
// }

void	load_byte_code(char **tokens)
{
	// static int	load_index = 0;

	if (!ft_strcmp(tokens[0], NAME_CMD_STRING)
	|| !ft_strcmp(tokens[0], COMMENT_CMD_STRING))
		return ;
	// load_ocp(tokens, &load_index);
	// for (int i = 0; i < load_index; i++)
		// ft_printf("[%x] ", g_load[i]);
}