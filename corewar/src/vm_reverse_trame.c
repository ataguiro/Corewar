/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_reverse_trame.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 14:25:23 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/14 14:37:10 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned long	vm_reverse_trame(char *input, size_t len)
{
	unsigned long	output;
	size_t			i;

	output = 0;
	i = 0;
	while (len)
		*((char *)(&output) + i++) = input[len--];
	return (output);
}
