/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_isdirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 23:10:19 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/12 17:35:15 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	is_all_digit(char *subject)
{
	int	i;

	i = -1;
	while (subject[++i])
		if (!ft_isdigit(subject[i]) && subject[i] != '-' && subject[i] != '+')
			return (0);
	return (1);
}

int	tl_isdirect(char *subject)
{
	if (subject[0] != '%')
		return (0);
	if (!subject[1])
		return (0);
	if (!is_all_digit(&subject[1]) && !tl_islabel_call(subject))
		return (0);
	return (1);
}
