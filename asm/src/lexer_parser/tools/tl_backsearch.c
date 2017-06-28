/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_backsearch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:49:39 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/28 14:27:54 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#define LC LABEL_CHAR

static int	loop(int *count, char **split, int j, char *the_label)
{
	char	**tokens;
	char	*saved;

	saved = NULL;
	while (--j >= 0)
	{
		tokens = ft_strsplit_whitespace(split[j]);
		if (tl_islabel(tokens[0]))
		{
			saved = ft_strdup(tokens[0]);
			ft_strrchr(saved, LABEL_CHAR) ? *ft_strrchr(saved, LC) = 0 : 0;
			if (!ft_strcmp(saved, the_label))
			{
				*count -= size_of_line(tokens);
				ft_strdel(&saved);
				ft_tabdel(&tokens);
				return (1);
			}
		}
		*count -= size_of_line(tokens);
		ft_tabdel(&tokens);
		ft_strdel(&saved);
	}
	return (0);
}

int			tl_backsearch(char **tokens, char **split, int i, int j)
{
	char	*the_label;
	char	*tmp;
	int		count;
	int		found;

	the_label = NULL;
	count = 0;
	tmp = ft_strchr(tokens[i], ':') + 1;
	the_label = ft_strdup(tmp);
	found = loop(&count, split, j + 1, the_label);
	found ? g_offtab[g_offset_index].label_name = the_label : free(the_label);
	found ? g_offtab[g_offset_index].offset = count : 0;
	g_offset_index += found;
	return (found);
}
