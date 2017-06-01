/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_remove_neg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 22:06:12 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/01 19:46:17 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_clean(char *s)
{
	int				j;
	size_t			i;
	int				dq;
	int				q;
	char			*new;

	j = 0;
	i = 0;
	q = 0;
	dq = 0;
	new = (char *)ft_memalloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	while (s[i])
	{
		s[i] == '"' && !(q % 2) ? dq++ : 0;
		s[i] == '\'' && !(dq % 2) ? q++ : 0;
		while ((s[i] == '"' && !(q % 2)) || (s[i] == '\'' && !(dq % 2)))
			i++;
		if (s[i] == -1)
			new[j] = ' ';
		else if (s[i] == -2)
			new[j] = '\t';
		else if (s[i] == -3)
			new[j] = '\n';
		else if (s[i] == -4)
			new[j] = ',';
		else
			new[j] = s[i];
		i++;
		j++;
	}
	new[i] = 0;
	return (new);
}

void			tl_remove_neg(char ***new)
{
	int			i;
	char		*tmp;

	i = 0;
	while ((*new)[i])
	{
		tmp = (*new)[i];
		(*new)[i] = ft_get_clean((*new)[i]);
		tmp ? free(tmp) : 0;
		i++;
	}
}
