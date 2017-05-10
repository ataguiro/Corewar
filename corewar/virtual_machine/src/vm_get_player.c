/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_get_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:19:51 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/10 14:34:36 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static int	vm_get_magic(char *str)
{
	int		num;

	num = str[0];
	num = (num << 8) + (char)str[1];
	num = (num << 8) + (char)str[2];
	num = (num << 8) + (char)str[3];
	return (num);
}

t_header	vm_get_player(char *str)
{
	t_header	header;

	header.magic = vm_get_magic(str);
	ft_memcpy(header.prog_name, str + 4, PROG_NAME_LENGTH + 1);
//	header.prog_size = 0;
	ft_memcpy(header.comment, str + 4 + PROG_NAME_LENGTH + 1, COMMENT_LENGTH + 1);
	ft_bzero(header.comment, COMMENT_LENGTH + 1);
	return (header);
}
