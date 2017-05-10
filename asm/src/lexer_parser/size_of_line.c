/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_of_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:19:23 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/10 15:28:53 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	excluded(char *ins)
{
	if (!ft_strcmp(ins, "live") || !ft_strcmp(ins, "zjmp")
	|| !ft_strcmp(ins, "fork") || !ft_strcmp(ins, "lfork"))
		return (1);
	return (0);
}

int			size_of_line(char **tokens)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (tl_islabel(tokens[i]))
		i++;
	if (tl_isinstruction(tokens[i]))
	{
		if (!excluded(tokens[i]))
			count += 2;
		else
			count++;
		while (tokens[++i])
		{
			if (tl_isregister(tokens[i]))
				count++;
			else if (tl_isdirect(tokens[i]))
				count += DIR_SIZE;
			else
				count += IND_SIZE;
		}
	}
	return (count);
}
