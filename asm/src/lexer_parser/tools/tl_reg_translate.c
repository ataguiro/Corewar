/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_reg_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:43:40 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/26 23:03:34 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define OPS "+-/*"

static int	l_affect(char *using, char *op)
{
	int		last;
	char	t;

	t = op ? *op : 0;
	t == '+' ? last = ft_atoi(using) + ft_atoi(op + 1) : 0;
	t == '-' ? last = ft_atoi(using) - ft_atoi(op + 1) : 0;
	t == '*' ? last = ft_atoi(using) * ft_atoi(op + 1) : 0;
	t == '/' ? last = ft_atoi(using) / ft_atoi(op + 1) : 0;
	if (t != '+' && t != '-' && t != '*' && t != '/')
		last = ft_atoi(using);
	return (last);
}

void	tl_reg_translate(char *reg, int *p)
{
	char	*op;
	char	*using;
	int		i;

	i = 0;
	op = NULL;
	while (reg[++i])
		if (!ft_isdigit(reg[i]) && ft_isinstr(reg[i], OPS) && i != 1)
		{
			op = &reg[i];
			break ;
		}
	op ? *op = 0 : 0;
	if (!tl_islabel_call(reg))
		using = ft_strdup(reg + 1);
	else
		using = ft_itoa(g_offtab[g_offset_index++].offset);
	g_load[(*p)++] = l_affect(using, op);
	free(using);
}
