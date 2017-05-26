/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_find_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:06:32 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/26 17:44:33 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_crd	nc_find_pos(size_t target)
{
	t_crd	crd;
	size_t	nb_sp;

	crd.y = target / LEN_LINE;
	nb_sp = target;
	target = target * 2 + nb_sp;
	crd.x = target % LEN_LINE;
	return (crd);
}
