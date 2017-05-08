/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:45:36 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/09 00:27:01 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

static void	build_header(int fd)
{
	char		*tmp;
	char		**split;
	static char	line[4096];
	header_t	header = (header_t){0, {0}, 0, {0}};

	(void)fd;
	header.magic = COREWAR_EXEC_MAGIC;
	header.prog_size = 0x42;
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
			ft_strcpy(header.prog_name, split[1]);
		else if (split[0] && split[1] && !ft_strcmp(split[0], COMMENT_CMD_STRING))
			ft_strcpy(header.comment, split[1]);
		else
			fatal_error();
		if (*header.prog_name && *header.comment)
			break ;
	}
	ft_printf("%p\n%p\n%s\n%s\n", header.magic, header.prog_size, header.prog_name, header.comment);
}

void	main_lexer(char *src_file)
{
	int	fd;

	fd = open(src_file, O_RDONLY);
	build_header(fd);
}
