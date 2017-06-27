/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 00:06:57 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/27 20:12:30 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	g_state = INS;
int	g_load[LARGE] = INIT_LOAD;
int	g_token_index = 0;

static int	is_blank(char *line)
{
	int	i;

	if (!line || !line[0])
		return (1);
	i = ~0;
	while (line[++i])
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
			return (0);
	return (1);
}

/*
**	add r1, %4, r5
**	[add] -> [r1]
*/

static void	analyse_buffer(char *buffer, char ***tokens, int *j)
{
	(void)tokens;
	if (tl_isinstruction(buffer))
		g_state = ARGS;
	if (!is_blank(buffer))
		(*tokens)[g_token_index++] = ft_strdup(buffer);
	ft_bzero(buffer, ft_strlen(buffer));
	*j = ~0;
}

static void	treat_line(char *line, int count)
{
	char	*buffer;
	char	**tokens;
	int		i;
	int		j;

	buffer = ft_strnew(ft_strlen(line));
	tokens = (char **)ft_memalloc(sizeof(char *) * ft_strlen(line));
	i = ~0;
	j = ~0;
	while (line[++i])
	{
		if (tl_islabel(buffer) && ft_isspace(line[i]))
		{
			ft_bzero(buffer, ft_strlen(buffer));
			j = ~0;
		}
		else if (g_state == INS && ft_isspace(line[i]))
			analyse_buffer(buffer, &tokens, &j);
		else if (g_state == ARGS && (line[i] == SEPARATOR_CHAR
			|| line[i] == '\n' || !line[i]))
			analyse_buffer(buffer, &tokens, &j);
		if (!ft_isspace(line[i]) && line[i] != SEPARATOR_CHAR)
			buffer[++j] = line[i];
	}
	token_parser(tokens, count);
	ft_strdel(&buffer);
	ft_tabdel(&tokens);
}

void		lexical_analyse(int fd)
{
	char	*line;
	char	*tmp;
	int		count;

	line = NULL;
	count = 0;
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_strchr(line, COMMENT_CHAR);
		tmp ? *tmp = 0 : 0;
		tmp = ft_strchr(line, ';');
		tmp ? *tmp = 0 : 0;
		tmp = line;
		line = ft_strjoin(line, "\n\x00");
		ft_strdel(&tmp);
		if (is_blank(line))
		{
			ft_strdel(&line);
			continue ;
		}
		++count;
		g_state = INS;
		treat_line(line, count);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}
