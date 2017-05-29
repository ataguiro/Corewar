/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 17:33:56 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/29 17:42:45 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_signal(int sign)
{
	if (sign == SIGINT || true)
	{
		wmove(g_env.win.w_info, 35, 2);
		wprintw(g_env.win.w_info, "num key %d", sign);
	}
}
