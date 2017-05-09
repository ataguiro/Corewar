/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:43:00 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/09 15:47:11 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

t_player	*vm_lst_new(t_header header)
{
	t_player	*n;

	if (!(n = malloc(sizeof(*n))))
		exit(EXIT_FAILURE);
	n->next = NULL;
	n->prev = NULL;
	return (n);
}
