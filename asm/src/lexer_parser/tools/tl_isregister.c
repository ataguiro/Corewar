/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_isregister.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 22:50:42 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/26 17:14:43 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	capitalize(char *subject)
{
	int	i;

	i = -1;
	if (subject[1] == '0' && (subject[2] == 'x' || subject[2] == 'X'))
	{
		while (subject[++i])
		{
			if (subject[i] >= 'a' && subject[i] <= 'z')
				subject[i] -= 32;
		}
	}
}

static void	switch_base(char *subject)
{
	int		ret;
	char	*tofill;

	if (subject[1] == '0' && subject[2] == 'X')
	{
		ret = ft_atoi_hex(subject + 3);
		tofill = ft_itoa(ret);
		ft_strcpy(subject + 1, tofill);
		free(tofill);
	}
}

int	tl_isregister(char *subject)
{
	int	check;

	if (subject[0] != 'r')
		return (0);
	capitalize(subject);
	switch_base(subject);
	check = ft_atoi(&subject[1]);
	if (check >= 0 && check <= 99)
		return (1);
	return (0);
}
