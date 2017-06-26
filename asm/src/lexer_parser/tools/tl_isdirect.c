/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_isdirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 23:10:19 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/26 17:23:55 by ataguiro         ###   ########.fr       */
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

// static void	capitalize(char *subject)
// {
// 	int	i;
//
// 	i = -1;
// 	if (subject[1] == '0' && (subject[2] == 'x' || subject[2] == 'X'))
// 	{
// 		while (subject[++i])
// 		{
// 			if (subject[i] >= 'a' && subject[i] <= 'z')
// 				subject[i] -= 32;
// 		}
// 	}
// }
//
// static void	switch_base(char *subject)
// {
// 	int		ret;
// 	char	*tofill;
//
// 	if (subject[1] == '0' && subject[2] == 'X')
// 	{
// 		ret = ft_atoi_hex(subject + 3);
// 		tofill = ft_itoa(ret);
// 		ft_strcpy(subject + 1, tofill);
// 		free(tofill);
// 	}
// }

int	tl_isdirect(char *subject)
{
	if (subject[0] != '%')
		return (0);
	if (!subject[1])
		return (0);
	// capitalize(subject);
	// switch_base(subject);
	if (!is_all_digit(&subject[1]) && !tl_islabel_call(subject))
		return (0);
	return (1);
}
