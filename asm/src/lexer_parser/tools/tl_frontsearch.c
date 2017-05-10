/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_frontsearch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:49:26 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/10 14:43:54 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	g_offset_index = 0;

static int	excluded(char *ins)
{
	if (!ft_strcmp(ins, "live") || !ft_strcmp(ins, "zjmp")
	|| !ft_strcmp(ins, "fork") || !ft_strcmp(ins, "lfork"))
		return (1);
	return (0);
}

static int	size_of_line(char **tokens)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (tl_islabel(tokens[i]))
		i++;
	if (tl_isinstruction(tokens[i]))
	{
		if (!excluded(tokens[i]))
			count += 2;
		else
			count++;
		while (tokens[++i])
		{
			if (tl_isregister(tokens[i]))
				count++;
			else if (tl_isdirect(tokens[i]))
				count += DIR_SIZE;
			else
				count += IND_SIZE;
		}
	}
	return (count);
}

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
				return (1);
		}
		*count += size_of_line(tokens);
		j++;
	}
	return (0);
}

int			tl_frontsearch(char **tokens, char **split, int i, int j)
{
	char	*the_label;
	char	*tmp;
	int		count;
	int		found;

	(void)j;
	(void)split;
	count = 0;
	tmp = ft_strchr(tokens[i], ':') + 1;
	the_label = ft_strdup(tmp);
	g_offtab[g_offset_index].label_name = the_label;
	count += size_of_line(tokens);
	found = loop_again(&count, split, j, the_label);
	ft_printf("%d - %d\n", found, count);
	return (count);
}
