/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_through_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 14:02:19 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/28 19:21:13 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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

void		loop_through_line(int fd, char **join, char **line, char **buffer)
{
	char	*tmp;

	while (get_next_line(fd, line) > 0)
	{
		(ft_strlen(*line) >= PROG_NAME_LENGTH \
		 || ft_strlen(*line) >= COMMENT_LENGTH) ? fatal_error() : 0;
		tmp = ft_strchr(*line, COMMENT_CHAR);
		tmp ? *tmp = 0 : 0;
		tmp = ft_strchr(*line, ';');
		tmp ? *tmp = 0 : 0;
		tmp = *line;
		*line = ft_strjoin(*line, "\n\x00");
		ft_strdel(&tmp);
		if (is_blank(*line))
		{
			ft_strdel(line);
			continue ;
		}
		*join = *buffer;
		*buffer = ft_strjoin(*join, *line);
		ft_strdel(join);
		ft_strdel(line);
	}
}
