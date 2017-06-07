/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:48:05 by folkowic          #+#    #+#             */
/*   Updated: 2017/06/07 16:40:21 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_fillbuf(const int fd, char **line)
{
	t_fl	fl;
	char	*tmp;

	fl.ret = 1;
	while (fl.ret && (!*line || (*line && !ft_strchr(*line, '\n'))))
	{
		fl.ret = read(fd, fl.buf, BUFF_SIZE);
		if (fl.ret < 0)
			return (fl.ret);
		fl.buf[fl.ret] = '\0';
		tmp = *line;
		*line = ft_strjoin(tmp, fl.buf);
		free(tmp);
	}
	return (fl.ret);
}

static t_list	*ft_lstmove(t_list **lst, int fd)
{
	t_list		*tmp;

	tmp = *lst;
	if (!*lst)
	{
		*lst = ft_lstnew(NULL, 0);
		(*lst)->content_size = fd;
	}
	while (tmp && (int)tmp->content_size != fd)
	{
		tmp = tmp->next;
	}
	if (!tmp)
	{
		tmp = ft_lstnew(NULL, 0);
		tmp->content_size = fd;
		ft_lstadd(lst, tmp);
	}
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*lst = NULL;
	t_list			*tmp;
	t_gnl			s;
	int				ret;

	tmp = ft_lstmove(&lst, fd);
	if (fd < 0 || !line || !tmp)
		return (-1);
	ret = ft_fillbuf(fd, (char **)&(tmp->content));
	if (!tmp->content || ret < 0)
		return (-1);
	s.p_str = ft_strchr((char *)tmp->content, '\n');
	s.len = ft_strclen((char *)tmp->content, '\n');
	s.p_str = ((char *)tmp->content + s.len);
	*s.p_str = '\0';
	ret > 0 ? s.p_str++ : 0;
	s.ret_str = ft_strdup((char *)tmp->content);
	*line = s.ret_str;
	s.new_str = ft_strdup(s.p_str);
	tmp->content ? free((char *)tmp->content) : 0;
	tmp->content = s.new_str;
	if (ret || **line)
		return (1);
	return (0);
}
