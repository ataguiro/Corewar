/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_get_offset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:31:02 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/28 10:06:20 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Read file to stock all needed offsets
**	for zjump instructions and prog_size (t_header)
*/

t_offset	g_offtab[MED];

static int	is_blank(char *line)
{
	int	i;

	if (!line || !line[0])
		return (1);
	i = -1;
	while (line[++i])
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
			return (0);
	return (1);
}

/*
**	%:label
**	count ++ ...
**	if not found:
**	count = 0; count -- ...
**	if found:
**	struct.i = count;
**	i++
*/

static int	currentsearch(char **tokens, int i)
{
	char	*the_label;
	char	*tmp;
	char	*saved;
	char	*potential_label;
	int		found;

	found = 0;
	tmp = ft_strchr(tokens[i], ':') + 1;
	the_label = ft_strdup(tmp);
	saved = ft_strdup(tokens[0]);
	potential_label = ft_strrchr(saved, LABEL_CHAR);
	potential_label ? *potential_label = 0 : 0;
	if (!ft_strcmp(saved, the_label))
		found = 1;
	found ? g_offtab[g_offset_index].label_name = the_label : free(the_label);
	found ? g_offtab[g_offset_index].offset = 0 : 0;
	g_offset_index += found;
	free(saved);
	return (found);
}

static void	analyse_tokens(char **tokens, char **split, int j)
{
	int	i;
	int	ret;
	int	islabel_call;
	static size_t count = 0;

	i = -1;
	ret = 0;
	while (tokens[++i])
	{
		islabel_call = tl_islabel_call(tokens[i]);
		if (islabel_call)
			ret = tl_frontsearch(tokens, split, i, j + 1);
		if (!ret && islabel_call)
			ret = tl_backsearch(tokens, split, i, j - 1);
		if (!ret && islabel_call)
			ret = currentsearch(tokens, i);
		if (!ret && islabel_call)
			fatal_error();
		if (g_offset_index >= (MED - 7))
			fatal_error();
	}
	++count;
}

static void	loop_through_split(char **split)
{
	char	**tokens;
	size_t	i;

	tokens = NULL;
	i = ~0;
	if (!split)
		return ;
	while (split[++i])
	{
		tokens = ft_strsplit_whitespace(split[i]);
		analyse_tokens(tokens, split, i);
		ft_tabdel(&tokens);
	}
}

void		lex_get_offset(int fd)
{
	char	*line;
	char	*buffer;
	char	*tmp;
	char	*join;
	char	**split;

	buffer = NULL;
	line = NULL;
	join = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (fd < 0)
			return ;
		tmp = ft_strchr(line, COMMENT_CHAR);
		tmp ? *tmp = 0 : 0;
		tmp = ft_strchr(line, ';');
		tmp ? *tmp = 0 : 0;
		tmp = line;
		line = ft_strjoin(line, "\n\x00");
		free(tmp);
		if (is_blank(line))
		{
			ft_strdel(&line);
			continue ;
		}
		join = buffer;
		buffer = ft_strjoin(join, line);
		ft_strdel(&join);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	ft_strdel(&join);
	split = ft_strsplit(buffer, '\n');
	loop_through_split(split);
	ft_tabdel(&split);
	ft_strdel(&buffer);
}
