/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_of_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:19:23 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/10 19:39:13 by ataguiro         ###   ########.fr       */
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

static int	set_mode(char **tokens)
{
	int	i;

	i = -1;
	while (tokens[++i])
		if (tl_islabel_call(tokens[i]))
			return (1);
	return (0);
}

int			size_of_line(char **tokens)
{
	int		i;
	int		count;
	int		label_mode;

	i = 0;
	count = 0;
	label_mode = set_mode(tokens);
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
				count += !label_mode ? DIR_SIZE : DIR_SIZE / 2;
			else
				count += IND_SIZE;
		}
	}
	return (count);
}
