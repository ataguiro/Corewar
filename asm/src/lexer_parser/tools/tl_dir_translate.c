/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_dir_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 11:33:12 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/17 16:11:01 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define OPS "+-*/"

void	tl_dir_translate(char *dir, int *p)
{
	int		last;
	int		i;
	char	*op;
	char	t;
	char	*using;

	i = 0;
	op = NULL;
	while (dir[++i])
		if (!ft_isdigit(dir[i]) && ft_isinstr(dir[i], OPS))
		{
			op = &dir[i];
			break ;
		}
	t = op ? *op : 0;
	op ? *op = 0 : 0;
	if (!tl_islabel_call(dir))
	{
		using = ft_strdup(dir);
		using++;
	}
	else
		using = ft_itoa(g_offtab[g_offset_index++].offset);
	ft_printf("[DEBUG] %s - %s - %d - %d\n", dir, using, g_offtab[g_offset_index - 1].offset, g_offset_index - 1);
	t == '+' ? last = ft_atoi(using) + ft_atoi(op + 1) : 0;
	t == '-' ? last = ft_atoi(using) - ft_atoi(op + 1) : 0;
	t == '*' ? last = ft_atoi(using) * ft_atoi(op + 1) : 0;
	t == '/' ? last = ft_atoi(using) / ft_atoi(op + 1) : 0;
	if (t != '+' && t != '-' && t != '*' && t != '/')
		last = ft_atoi(using);
	g_load[(*p)++] = last;
}
