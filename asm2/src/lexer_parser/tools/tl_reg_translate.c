/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_reg_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:43:40 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/15 17:40:48 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define OPS "+-/*"

void	tl_reg_translate(char *reg, int *p)
{
	int		last;
	int		i;
	char	*op;
	char	*using;
	char	t;

	i = 0;
	op = NULL;
	while (reg[++i])
		if (!ft_isdigit(reg[i]) && ft_isinstr(reg[i], OPS))
		{
			op = &reg[i];
			break ;
		}
	t = op ? *op : 0;
	op ? *op = 0 : 0;
	if (!tl_islabel_call(reg))
	{
		using = ft_strdup(reg);
		using++;
	}
	else
		using = ft_itoa(g_offtab[g_offset_index++].offset);
	t == '+' ? last = ft_atoi(using) + ft_atoi(op + 1) : 0;
	t == '-' ? last = ft_atoi(using) - ft_atoi(op + 1) : 0;
	t == '*' ? last = ft_atoi(using) * ft_atoi(op + 1) : 0;
	t == '/' ? last = ft_atoi(using) / ft_atoi(op + 1) : 0;
	if (t != '+' && t != '-' && t != '*' && t != '/')
		last = ft_atoi(using);
	g_load[(*p)++] = last;
}
