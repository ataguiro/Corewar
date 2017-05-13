/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:53:08 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/13 03:04:18 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_type(int i, char **tokens)
{
	int	*tmp;
	int	i;

	tmp = g_optab[i].arg_type;
	i = -1;
	while (tokens[++i])
	{
		if (tl_isdirect(tokens[i]) && (tmp[i] == 3 || tmp[i] == 6 || tmp[i] == 2))
			;
		else if (tl_isregister(tokens[i]) && (tmp[i] == 1 || tmp[i] == 5 || tmp[i] == 3))
			;
		else if (tmp[i] == 4 || tmp[i] == 5 || tmp[i] == 6)
			;
		else
			return (0);
	}
	return (1);
}

static int	check(char *ins, char **tokens)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	(void)tokens;
	if (!tl_isinstruction(ins))
		return (0);
	while (++i < 16)
		if (!ft_strcmp(ins, g_optab[i].ins_name))
			break ;
	while (tokens[++j])
		;
	if (j != g_optab[i].max_arg)
		return (0);
	return (check_type(i, tokens));
}

void		token_parser(char **tokens)
{
	// for (int i = 0; i < g_token_index; i++)
	// 	ft_printf("[%s] - ", tokens[i]);
	// ft_printf("NIL\n");
	int	off;

	off = 0;
	if (tl_islabel(tokens[0]))
		++off;
	check(tokens[off], tokens + off + 1);
	ft_tabdel(&tokens);
	g_token_index = 0;
}
