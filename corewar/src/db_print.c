/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:05:05 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/11 14:13:23 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*vm_print(unsigned char player, unsigned char cursor)
{
	static char str[] = "\033[00;000;00m";

	if (player == 1)
		ft_strcpy(str + 2, "32");
	return (str);
}