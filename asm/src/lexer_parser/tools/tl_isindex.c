/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_isindex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:26:25 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/28 14:56:26 by folkowic         ###   ########.fr       */
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

int			tl_isindex(char *subject)
{
	if (!subject)
		return (0);
	capitalize(subject);
	switch_base(subject);
	if (!is_all_digit(subject) && !tl_islabel_call(subject))
		return (0);
	return (1);
}
