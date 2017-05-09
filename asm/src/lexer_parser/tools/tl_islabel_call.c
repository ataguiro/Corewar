/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_islabel_call.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:58:24 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/09 18:19:02 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	tl_islabel_call(char *subject)
{
	int	i;

	i = 0;
	if (subject[0] != LABEL_CHAR && subject[1] != LABEL_CHAR)
		return (0);
	if (subject[0] != LABEL_CHAR && subject[1] == LABEL_CHAR)
		i += 2;
	if (subject[0] == LABEL_CHAR)
		i++;
	while (subject[i++])
	{
		if (!ft_isinstr(subject[i], LABEL_CHARS))
			return (0);
	}
	return (1);
}
