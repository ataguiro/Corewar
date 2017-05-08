/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 18:55:11 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/08 15:23:06 by echo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	usage(void)
{
	ft_printf("Usage:\n./asm [-ha] <src_file.s>\n");
	exit(1);
}

static char	*get_src(char **av)
{
	int		i;
	char	*src_file;

	i = 0;
	while (av[++i])
	{
		if (!(av[i][0] ^ '-'))
			continue ;
		src_file = ft_strdup(av[i]);
		break ;
	}
	if (ft_strlen(src_file) > 2 && ft_strcmp(&src_file[ft_strlen(src_file) - 2], ".s"))
		ft_printf("asm: \033[33mwarning: you entered %s as source file, \
but it's bad prefixed\033[0m\n", src_file);
	return (src_file);
}

int			main(int ac, char **av,char **ev)
{
	(void)ev;
	(void)ac;
	char	options;
	char	*src_file;

	options = get_options(av);
	options++;
	if (ac < 2 || ISON(options, OPT_H))
		usage();
	src_file = get_src(av);
	main_lexer(src_file);
	return (0);
}
