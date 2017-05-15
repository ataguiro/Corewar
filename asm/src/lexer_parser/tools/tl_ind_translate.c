/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_ind_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:53:28 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/15 17:44:03 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define OPS "+-/*"

void	tl_ind_translate(char *ind, int *p)
{
	int		last;
	int		i;
	char	*op;
	char	*using;
	char	t;

	i = 0;
	op = NULL;
	while (ind[++i])
		if (!ft_isdigit(ind[i]) && ft_isinstr(ind[i], OPS))
		{
			op = &ind[i];
			break ;
		}
	t = op ? *op : 0;
	op ? *op = 0 : 0;
	if (!tl_islabel_call(ind))
		using = ft_strdup(ind);
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
