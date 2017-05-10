/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:43:00 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/10 11:24:08 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

t_player	*vm_lst_new(void)
{
	t_player	*n;

	if (!(n = malloc(sizeof(*n))))
		exit(EXIT_FAILURE);
	n->header = (t_header){0, {'\0'}, 0, {'\0'}};
	n->next = NULL;
	n->prev = NULL;
	return (n);
}
