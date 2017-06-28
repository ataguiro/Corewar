/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:36:57 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/28 15:00:12 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_tab(long *hextab)
{
	int	i;

	i = -1;
	while (++i < 255)
		hextab[i] = -1;
	i = '0' - 1;
	while (++i <= '9')
		hextab[i] = i - '0';
	i = 'A' - 1;
	while (++i <= 'F')
		hextab[i] = i - '0' - 7;
}

long		ft_atoi_hex(char *n)
{
	long hextab[255];
	long ret;

	ret = 0;
	fill_tab(hextab);
	while (*n && ret >= 0)
		ret = (ret << 4) | hextab[(long)*n++];
	return (ret);
}
