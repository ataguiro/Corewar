/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_search_slot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:50:28 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/04 03:03:51 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	se_search_slot(void)
{
	int	i;

	i = -1;
	sleep(1);
	while (g_client[++i].connected)
		;
	if (i > 4)
		i = 4;
	return (i);
}