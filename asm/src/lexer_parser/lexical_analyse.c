/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 00:06:57 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/11 15:12:18 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	g_state = INS;
int	g_load[14] = {0};
int	g_token_index = 0;

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
**	add r1, %4, r5
**	[add] -> [r1]
*/

static void	analyse_buffer(char *buffer, char ***tokens, int *j)
{
	if (tl_isinstruction(buffer))
		g_state = ARGS;
	if (!is_blank(buffer))
		(*tokens)[g_token_index++] = ft_strdup(buffer);
	ft_bzero(buffer, ft_strlen(buffer));
	*j = -1;
}

static void	treat_line(char *line)
{
	char	*buffer;
	char	**tokens;
	int		i;
	int		j;

	buffer = ft_strnew(ft_strlen(line));
	tokens = (char **)ft_memalloc(sizeof(char *) * 7);
	i = -1;
	j = -1;
	while (line[++i])
	{
		if (tl_islabel(buffer) && ft_isspace(line[i]))
		{
			ft_bzero(buffer, ft_strlen(buffer));
			j = -1;
		}
		else if (g_state == INS && ft_isspace(line[i]))
			analyse_buffer(buffer, &tokens, &j);
		else if (g_state == ARGS && (line[i] == SEPARATOR_CHAR
			|| line[i] == '\n' || !line[i]))
			analyse_buffer(buffer, &tokens, &j);
		if (!ft_isspace(line[i]) && line[i] != SEPARATOR_CHAR)
			buffer[++j] = line[i];
	}
	token_parser(tokens);
}

void		lexical_analyse(int fd)
{
	char	line[4096];
	char	*tmp;

	while (ft_readline(line, fd) > 0)
	{
		tmp = ft_strchr(line, COMMENT_CHAR);
		tmp ? *tmp = 0 : 0;
		tmp = ft_strchr(line, ';');
		tmp ? *tmp = 0 : 0;
		ft_strcat(line, "\n\x00");
		if (is_blank(line))
			continue ;
		g_state = INS;
		treat_line(line);
	}
}
