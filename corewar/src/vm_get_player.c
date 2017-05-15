/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_get_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:19:51 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/15 15:36:51 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** reverse string value to integer
** str = 3f38ae
** return = ea83f3
*/

static int	l_rev_int(char *str, size_t len)
{
	size_t	i;
	int		num;

	i = -1;
	num = str[++i] & 0xff;
	while (++i < len)
		num = (num << 8) + (str[i] & 0xff);
	return (num);
}

/*
** show define in virtual_machine.h for show offset calcul
** str = |magic|prog_name|prog_size|empty|champion code|
*/

t_header	vm_get_player(char *str)
{
	t_header	header;

	header.magic = l_rev_int(str, LEN_MAGIC);
	ft_memcpy(header.prog_name, str + OFFSET_PROG_NAME, PROG_NAME_LENGTH);
	header.prog_size = l_rev_int(str + OFFSET_PROG_SIZE, LEN_PROG_SIZE);
	ft_memcpy(header.comment, str + OFFSET_COMMENT, COMMENT_LENGTH);
	return (header);
}
