/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_secure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 18:20:25 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/06 17:49:21 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	se_secure(int element)
{
	if (element < 0)
		se_fatal();
}
