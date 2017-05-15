/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_byte_code.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 21:40:03 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/15 17:38:24 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_header	g_header = (t_header){0, {0}, 0, {0}};

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

void		write_byte_code(char *src)
{
	int		out_fd;
	char	*dst;
	char	*ptr;

	dst = ft_strnew(ft_strlen(src) + 3);
	ptr = ft_strstr(src, ".s");
	ptr ? *ptr = 0 : 0;
	ft_strcpy(dst, src);
	ft_strcat(dst, PREFIX);
	out_fd = open(dst, O_WRONLY | O_APPEND | O_CREAT | O_TRUNC, 0744);
	write_header(out_fd);
	for (int i = 0; i <= 5; i++)
		ft_printf("TEST DG %hhx -> %s\n", g_load[i], tl_isbyte_instruction(g_load[i]) ? "yes" : "no");
	return ;
}
