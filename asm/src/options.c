/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 19:15:33 by ataguiro          #+#    #+#             */
/*   Updated: 2017/04/10 15:35:48 by echo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	save_data(char *str, char* options)
{
	int			i;
	static int	check = 0;

	i = -1;
	if (str[++i] == '-')
		while (str[++i])
		{
			if (str[i] == 'a')
				(*options) |= OPT_A;
			if (str[i] == 'h')
				(*options) |= OPT_H;
		}
	else
		++check;
	(check > 2) ? fatal_error() : 0;
}

char		get_options(char **av)
{
	char	options;
	int		i;

	options = 0;
	i = -1;
	while (av[++i])
		save_data(av[i], &options);
	return (options);
}
