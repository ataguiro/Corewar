/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_whitespace.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:33:25 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/10 14:06:08 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"

static int	count_words(char *s)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == ',')
			i++;
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i] != 0 && s[i] != ',')
			count++;
		while (s[i] != ' ' && s[i] != '\t' && s[i] != '\n'  && s[i] != 0 && s[i] != ',')
			i++;
	}
	return (count);
}

static int	count_char(char *s)
{
	int		count;

	count = 0;
	while (s[count])
	{
		if (s[count] == ' ' || s[count] == '\t' || s[count] == '\n' || s[count] == ',')
			break ;
		count++;
	}
	return (count);
}

char		**ft_strsplit_whitespace(char *s)
{
	t_infos2	info;

	if (!s)
		return (NULL);
	tl_set_neg(&s);
	info.words = count_words(s);
	info.new = (char **)ft_memalloc(sizeof(char *) * (info.words + 2));
	info.i = 0;
	info.t = 0;
	if (!info.new)
		return (NULL);
	while (info.t < info.words)
	{
		while (s[info.i] != 0 && (s[info.i] == ' ' || s[info.i] == '\t' ||
		s[info.i] == '\n' || s[info.i] == ','))
			info.i++;
		info.new[info.t] = ft_strsub(&s[info.i], 0, count_char(&s[info.i]));
		info.t++;
		while (s[info.i] != 0 && s[info.i] != ' ' && s[info.i] != '\t' &&
		s[info.i] != '\n' && s[info.i] != ',')
			info.i++;
	}
	info.new[info.words] = NULL;
	tl_remove_neg(&info.new);
	return (info.new);
}
