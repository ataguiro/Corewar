/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_get_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:19:51 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/09 17:55:46 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

t_header	vm_get_player(char *str)
{
	t_header	header;

	header.magic = 0;
	ft_strcpy(header.prog_name, str);
	header.prog_size = 0;
	ft_strcpy(header.comment, "ton pere");
	return (header);
}
