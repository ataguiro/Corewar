/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_islabel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:07:14 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/28 14:41:06 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	tl_islabel(char *subject)
{
	int	i;

	i = -1;
	while (subject && subject[++i] && subject[i + 1])
	{
		if (!(ft_isinstr(subject[i], LABEL_CHARS)))
			return (0);
	}
	if (subject[i] != LABEL_CHAR)
		return (0);
	return (1);
}
