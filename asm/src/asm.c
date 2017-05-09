/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 18:55:11 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/08 23:46:28 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	usage(void)
{
	ft_printf("Usage:\n./asm [-ha] <src_file.s>\n");
	exit(EXIT_FAILURE);
}

static char	*get_src(char **av)
{
	int		i;
	char	*src_file;

	i = 0;
	src_file = NULL;
	while (av[++i])
	{
		if (!(av[i][0] ^ '-'))
			continue ;
		src_file = ft_strdup(av[i]);
		break ;
	}
	if (!src_file)
		fatal_error();
	return (src_file);
}

int			main(int ac, char **av,char **ev)
{
	char	options;
	char	*src_file;

	(void)ev;
	options = get_options(av);
	options++;
	if (ac < 2 || ISON(options, OPT_H))
		usage();
	src_file = get_src(av);
	main_lexer(src_file);
	return (0);
}