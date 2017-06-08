/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_ind_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:53:28 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/08 12:08:49 by folkowic         ###   ########.fr       */
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

void	tl_ind_translate(char *ind, int *p)
{
	char	*op;
	char	*using;
	int		i;

	i = 0;
	op = NULL;
	while (ind[++i])
		if (!ft_isdigit(ind[i]) && ft_isinstr(ind[i], OPS))
		{
			op = &ind[i];
			break ;
		}
	op ? *op = 0 : 0;
	if (!tl_islabel_call(ind))
		using = ft_strdup(ind);
	else
		using = ft_itoa(g_offtab[g_offset_index++].offset);
	g_load[(*p)++] = l_affect(using, op);
	free(using);
}
