/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:53:08 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/11 15:50:55 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check(char *ins, char **tokens)
{
	int	i;

	i = -1;
	(void)tokens;
	while (++i < 16)
		if (!ft_strcmp(ins, g_optab[i].ins_name))
			break ;
	ft_printf("=== CHECK ===\n%s\n", g_optab[i].ins_name);
	return (1);
}

void		token_parser(char **tokens)
{
	for (int i = 0; i < g_token_index; i++)
		ft_printf("[%s] - ", tokens[i]);
	ft_printf("NIL\n");
	check(tokens[0], tokens + 1);
	g_token_index = 0;
}
