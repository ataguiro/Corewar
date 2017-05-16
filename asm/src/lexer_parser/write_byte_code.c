/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_byte_code.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 21:40:03 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/16 15:08:14 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	write_header(int fd)
{
	int	big_magic;
	int	big_size;

	big_magic = tl_bigendian(g_header.magic);
	big_size = tl_bigendian(g_header.prog_size);
	write(fd, &big_magic, 4);
	write(fd, g_header.prog_name, PROG_NAME_LENGTH);
	write(fd, &big_size, 4);
	write(fd, g_header.comment, COMMENT_LENGTH);
}

static int	excluded(char *ins)
{
	if (!ft_strcmp(ins, "live") || !ft_strcmp(ins, "zjmp")
	|| !ft_strcmp(ins, "fork") || !ft_strcmp(ins, "lfork"))
		return (1);
	return (0);
}

static void	write_core(int fd)
{
	int	i;
	// int	j;
	int	flag;
	int	*size_tab;

	i = 0;
	flag = 0;
}

void		write_byte_code(char *src)
{
	int		out_fd;
	char	*dst;
	char	*ptr;

	if (g_leave)
		return ;
	dst = ft_strnew(ft_strlen(src) + 3);
	ptr = ft_strstr(src, ".s");
	ptr ? *ptr = 0 : 0;
	ft_strcpy(dst, src);
	ft_strcat(dst, PREFIX);
	out_fd = open(dst, O_WRONLY | O_APPEND | O_CREAT | O_TRUNC, 0744);
	write_header(out_fd);
	write_core(out_fd);
	return ;
}
