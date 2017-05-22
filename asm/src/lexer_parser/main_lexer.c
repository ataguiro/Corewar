/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:45:36 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/22 11:34:01 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_header	g_header = (t_header){0, {0}, 0, {0}};

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

static int	get_prog_size(int fd)
{
	char	**tokens;
	char	line[LARGE];
	char	*tmp;
	int		count;

	count = 0;
	while (ft_readline(line, fd) > 0)
	{
		tmp = ft_strchr(line, '#');
		tmp ? *tmp = 0 : 0;
		tmp = ft_strchr(line, ';');
		tmp ? *tmp = 0 : 0;
		if (is_blank(line))
			continue ;
		tokens = ft_strsplit_whitespace(line);
		count += size_of_line(tokens);
	}
	lseek(fd, 0, SEEK_SET);
	return (count);
}

static void	build_header(int fd)
{
	char			*tmp;
	char			**split;
	static char		line[4096] = {0};

	g_header.magic = COREWAR_EXEC_MAGIC;
	g_header.prog_size = get_prog_size(fd);
	while (ft_readline(line, fd) > 0)
	{
		tmp = ft_strchr(line, '#');
		tmp ? *tmp = 0 : 0;
		tmp = ft_strchr(line, ';');
		tmp ? *tmp = 0 : 0;
		if (is_blank(line))
			continue ;
		split = ft_strsplit_whitespace(line);
		if (split[0] && split[1] && !ft_strcmp(split[0], NAME_CMD_STRING))
			ft_strcpy(g_header.prog_name, split[1]);
		else if (split[0] && split[1] && !ft_strcmp(split[0], COMMENT_CMD_STRING))
			ft_strcpy(g_header.comment, split[1]);
		else if (*g_header.prog_name)
			break ;
		else
			fatal_error();
		if (*g_header.prog_name && *g_header.comment)
			break ;
	}
	if (!(*g_header.prog_name))
		fatal_error();
}

void	main_lexer(char *src_file)
{
	int	fd;

	fd = open(src_file, O_RDONLY);
	lex_get_offset(fd);
	g_offset_index = 0;
	lseek(fd, 0, SEEK_SET);
	build_header(fd);
	lseek(fd, 0, SEEK_SET);
	lexical_analyse(fd);
	write_byte_code(src_file);
}
