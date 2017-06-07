/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_frontsearch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:49:26 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/07 15:22:15 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	g_offset_index = 0;

static int	loop_again(int *count, char **split, int j, char *the_label)
{
	char	**tokens;
	char	*saved;
	char	*potential_label;

	saved = NULL;
	while (split[j])
	{
		tokens = ft_strsplit_whitespace(split[j]);
		if (tl_islabel(tokens[0]))
		{
			saved = ft_strdup(tokens[0]);
			potential_label = ft_strrchr(saved, LABEL_CHAR);
			potential_label ? *potential_label = 0 : 0;
			if (!ft_strcmp(saved, the_label))
			{
				ft_tabdel(&tokens);
				ft_strdel(&saved);
				return (1);
			}
		}
		*count += size_of_line(tokens);
		ft_tabdel(&tokens);
		ft_strdel(&saved);
		j++;
	}
	// ft_tabdel(&tokens);
	// ft_strdel(&saved);
	return (0);
}

int			tl_frontsearch(char **tokens, char **split, int i, int j)
{
	char	*the_label;
	char	*tmp;
	int		count;
	int		found;

	the_label = NULL;
	count = 0;
	tmp = ft_strchr(tokens[i], ':') + 1;
	the_label = ft_strdup(tmp);
	count += size_of_line(tokens);
	found = loop_again(&count, split, j, the_label);
	found ? g_offtab[g_offset_index].label_name = the_label : free(the_label);
	found ? g_offtab[g_offset_index].offset = count : 0;
	g_offset_index += found;
	return (found);
}
