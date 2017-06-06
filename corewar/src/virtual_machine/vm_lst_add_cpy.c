/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_lst_add_cpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:15:53 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/26 17:26:30 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_process	*l_lst_cpy(t_process *process)
{
	t_process	*cpy;

	if (!(cpy = malloc(sizeof(*cpy))))
		exit(EXIT_FAILURE);
	ft_memcpy(cpy, process, sizeof(*process));
	cpy->next = NULL;
	cpy->prev = NULL;
	return (cpy);
}

void				vm_lst_add_cpy(t_process **lst)
{
	t_process	*cpy;

	cpy = l_lst_cpy(*lst);
	if (lst)
	{
		if (!*lst)
			*lst = cpy;
		else
		{
			cpy->next = g_env.process;
			g_env.process->prev = cpy;
			g_env.process = cpy;
		}
	}
}
