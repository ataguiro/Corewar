/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_backsearch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:49:39 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/18 15:12:54 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	loop(int *count, char **split, int j, char *the_label)
{
	char	**tokens;
	char	*saved;
	char	*potential_label;

	saved = NULL;
	while (j >= 0)
	{
		tokens = ft_strsplit_whitespace(split[j]);
		if (tl_islabel(tokens[0]))
		{
			saved = ft_strdup(tokens[0]);
			potential_label = ft_strrchr(saved, LABEL_CHAR);
			potential_label ? *potential_label = 0 : 0;
			if (!ft_strcmp(saved, the_label))
			{
				*count -= size_of_line(tokens);
				return (1);
			}
		}
		*count -= size_of_line(tokens);
		j--;
	}
	return (0);
}

int			tl_backsearch(char **tokens, char **split, int i, int j)
{
	char	*the_label;
	char	*tmp;
	int		count;
	int		found;

	count = 0;
	tmp = ft_strchr(tokens[i], ':') + 1;
	the_label = ft_strdup(tmp);
	found = loop(&count, split, j, the_label);
	found ? g_offtab[g_offset_index].label_name = the_label : 0;
	found ? g_offtab[g_offset_index].offset = count : 0;
	g_offset_index += found;
	return (found);
}
