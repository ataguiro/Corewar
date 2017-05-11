/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:53:08 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/11 14:56:38 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	token_parser(char **tokens)
{
	for (int i = 0; i < g_token_index; i++)
		ft_printf("[%s] - ", tokens[i]);
	ft_printf("NIL\n");
	g_token_index = 0;
}
