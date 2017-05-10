/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_islabel_call.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:58:24 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/10 23:53:53 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	tl_islabel_call(char *subject)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strrchr(subject, SEPARATOR_CHAR);
	tmp ? *tmp = 0 : 0;
	if (subject[0] != LABEL_CHAR && subject[1] != LABEL_CHAR)
		return (0);
	if (subject[0] != LABEL_CHAR && subject[1] == LABEL_CHAR)
		i += 2;
	if (subject[0] == LABEL_CHAR)
		i++;
	while (subject[i])
	{
		if (subject[i] == '+' || subject[i] == '-' || subject[i] == ' ')
		{
			subject[i] = 0;
			return (1);
		}
		if (!ft_isinstr(subject[i], LABEL_CHARS))
			return (0);
		i++;
	}
	return (1);
}
