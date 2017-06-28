/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:16:12 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/28 10:13:18 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabdel(char ***tab)
{
	size_t	i;

	i = 0;
	if (!(*tab))
		return ;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		i++;
	}
	if (*tab)
		free(*tab);
	*tab = NULL;
}
