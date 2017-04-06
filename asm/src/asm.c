/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 18:55:11 by ataguiro          #+#    #+#             */
/*   Updated: 2017/04/06 20:17:24 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int main(int ac, char **av, char **ev)
{
	(void)ev;
	(void)ac;
	char	options;

	options = get_options(av);
	ft_printf("options --> 0b%08b\n", (int)options);
}
