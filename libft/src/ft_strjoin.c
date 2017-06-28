/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 22:58:31 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/28 17:08:06 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	s1 ? i = ft_strlen(s1) : 0;
	s2 ? j = ft_strlen(s2) : 0;
	new = (char *)ft_memalloc(sizeof(char) * (i + j + 1));
	if (!new)
		return (NULL);
	s1 ? ft_strcpy(new, (char *)s1) : 0;
	s2 ? ft_strcpy(new + i, (char *)s2) : 0;
	return (new);
}
