/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_check_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:54:16 by folkowic          #+#    #+#             */
/*   Updated: 2017/06/06 18:46:35 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	l_error_size(void)
{
	ft_dprintf(2, "Prog length is too low\n");
	exit(EXIT_FAILURE);
}

void		vm_check_length(int argc, char **argv)
{
	char	buf[1 + 1];
	size_t	total;
	int		i;
	int		fd;
	int		ret;

	printf("LENGTH %d\n", MIN_LEN);
	i = 1;
	while (++i < argc)
	{
		total = 0;
		if (argv[i][0] == '-')
			continue ;
		if ((fd = open(argv[i], O_RDONLY)) < 0)
			continue ;
		while ((ret = read(fd, buf, 1)) > 0)
			total += ret;
		close(fd);
		if (total < MIN_LEN)
			l_error_size();
	}
}
