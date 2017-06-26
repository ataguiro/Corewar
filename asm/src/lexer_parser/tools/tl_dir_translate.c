/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_dir_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 11:33:12 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/26 23:11:11 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define OPS "+-*/"

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

void	tl_dir_translate(char *dir, int *p)
{
	char	*op;
	char	*using;
	int		i;

	i = 0;
	op = NULL;
	while (dir[++i])
		if (!ft_isdigit(dir[i]) && ft_isinstr(dir[i], OPS) && i != 1)
		{
			op = &dir[i];
			break ;
		}
	op ? *op = 0 : 0;
	if (!tl_islabel_call(dir))
		using = ft_strdup(dir + 1);
	else
		using = ft_itoa(g_offtab[g_offset_index++].offset);
	g_load[(*p)++] = l_affect(using, op);
	free(using);
}
