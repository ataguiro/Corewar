/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:05:05 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/20 16:20:38 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*db_print(unsigned char process, unsigned char cursor)
{
	static char str[] = "\033[00;000;00m";

	if (process == 1)
		ft_strcpy(str + 2, "32");
	return (str);
}
