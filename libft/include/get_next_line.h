/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:48:12 by folkowic          #+#    #+#             */
/*   Updated: 2017/06/07 16:40:48 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include "libft.h"
# define BUFF_SIZE 48

typedef struct	s_fl
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
}				t_fl;

typedef struct	s_content
{
	char	*str;
	int		fd;
}				t_content;

typedef struct	s_gnl
{
	char	*p_str;
	char	*new_str;
	char	*ret_str;
	char	*fin_str;
	size_t	len;
}				t_gnl;

int				get_next_line(const int fd, char **line);

#endif
