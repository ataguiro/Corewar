/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_get_offset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:31:02 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/10 15:50:15 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "asm.h"

/*
**	Read file to stock all needed offsets
**	for zjump instructions and prog_size (t_header)
*/

t_offset	g_offtab[256];

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

static void	analyse_tokens(char **tokens, char **split, int j)
{
	int	i;
	int	ret;

	i = -1;
	ret = 0;
	while (tokens[++i])
	{
		if (tl_islabel_call(tokens[i]))
			ret = tl_frontsearch(tokens, split, i, j + 1);
		if (!ret && tl_islabel_call(tokens[i]))
			tl_backsearch(tokens, split, i, j - 1);
	}
}

static void	loop_through_split(char **split)
{
	int		i;
	char	**tokens;

	i = -1;
	while (split[++i])
	{
		tokens = ft_strsplit_whitespace(split[i]);
		analyse_tokens(tokens, split, i);
	}
}

void		lex_get_offset(int fd)
{
	char	line[4096];
	char	*buffer;
	char	*tmp;
	char	**split;

	buffer = NULL;
	while (ft_readline(line, fd) > 0)
	{
		tmp = ft_strchr(line, '#');
		tmp ? *tmp = 0 : 0;
		tmp = ft_strchr(line, ';');
		tmp ? *tmp = 0 : 0;
		ft_strcat(line, "\n\x00");
		if (is_blank(line))
			continue ;
		buffer = ft_strjoin(buffer, line);
	}
	split = ft_strsplit(buffer, '\n');
	loop_through_split(split);
	for (int i = 0; i < g_offset_index; i++)
		ft_printf("[%s] : %d\n", g_offtab[i].label_name, g_offtab[i].offset);
}
