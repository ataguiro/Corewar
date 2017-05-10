/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 00:06:57 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/11 01:02:29 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	g_state = INS;
int	g_load[14] = {0};

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

static int	treat_line(char *line)
{
	char	buffer[512];
	int		i;

	ft_memset(buffer, 0, 512);
	i = -1;
	while (line[++i])
	{
		
	}
}

static void	throw_error(int ret)
{
	if (ret)
	{
		ft_printf("error\n");
		exit(1);
	}
}

void		lexical_analyse(int fd)
{
	char	line[4096];
	char	*tmp;
	int		ret;

	while (ft_readline(line, fd) > 0)
	{
		tmp = ft_strchr(line, COMMENT_CHAR);
		tmp ? *tmp = 0 : 0;
		tmp = ft_strchr(line, ';');
		tmp ? *tmp = 0 : 0;
		ft_strcat(line, "\n\x00");
		if (is_blank(line))
			continue ;
		ret = treat_line(line);
		throw_error(ret);
	}
}