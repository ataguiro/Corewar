/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_ocp_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:25:04 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/15 23:31:52 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	*tl_ocp_translate(char ocp, int j)
{
	static int	result[3];
	int			tmp;

	tmp = 0;
	ft_memset(result, 0, 3);
	if (ocp & 0b)
}