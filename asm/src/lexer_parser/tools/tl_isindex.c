/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_isindex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:26:25 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/13 14:32:01 by ataguiro         ###   ########.fr       */
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

int			tl_isindex(char	*subject)
{
	if (!is_all_digit(subject) && !tl_islabel_call(subject))
		return (0);
	return (1);
}