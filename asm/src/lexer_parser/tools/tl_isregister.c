/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_isregister.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 22:50:42 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/09 23:19:24 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	tl_isregister(char *subject)
{
	int	check;

	check = ft_atoi(&subject[1]);
	if (subject[0] != 'r')
		return (0);
	if (check > 0 && check <= REG_NUMBER)
		return (1);
	return (0);
}