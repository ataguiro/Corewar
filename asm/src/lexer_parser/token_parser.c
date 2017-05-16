/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:53:08 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/16 12:42:17 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		g_leave = 0;
char	g_errno[MED] = {0};

static char	*check_type(int i, char **tokens)
{
	int	*tmp;
	int	j;

	tmp = g_optab[i].arg_type;
	j = -1;
	while (tokens[++j])
	{
		if (tl_isdirect(tokens[j]) && (tmp[j] == 3 || tmp[j] == 6
		|| tmp[j] == 2 || tmp[j] == 7))
			;
		else if (tl_isregister(tokens[j]) && (tmp[j] == 1 || tmp[j] == 5
		|| tmp[j] == 3 || tmp[j] == 7))
			;
		else if (tl_isindex(tokens[j]) && (tmp[j] == 4 || tmp[j] == 5
		|| tmp[j] == 6 || tmp[j] == 7))
			;
		else
			return (tokens[j]);
	}
	return (NULL);
}

static void	prepare_and_send(char *item, int line, char **tokens)
{
	char	load[MED];

	ft_memset(load, 0, MED);
	load[0] = '`';
	ft_strcat(load, item);
	ft_strcat(load, "' is not an instruction");
	tl_seterrno(load, tokens, line, INS_ERROR);
}

static int	check(char *ins, char **tokens, int count)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	if (!ft_strcmp(ins, NAME_CMD_STRING) || !ft_strcmp(ins, COMMENT_CMD_STRING))
		return (1);
	(!tl_isinstruction(ins)) ? prepare_and_send(ins, count, tokens) : 0;
	if (!tl_isinstruction(ins))
		return (0);
	while (++i < 16)
		if (!ft_strcmp(ins, g_optab[i].ins_name))
			break ;
	j = ft_tablen(tokens + 1);
	if (j != g_optab[i].max_arg)
	{
		tl_seterrno(NULL, tokens, count, NUM_ERROR);
		return (0);
	}
	if ((tmp = check_type(i, tokens + 1)))
	{
		tl_seterrno(tmp, tokens, count, PAR_ERROR);
		return (0);
	}
	return (1);
}

void		token_parser(char **tokens, int count)
{
	int	ret;

	if (!tokens[0])
		return ;
	for (int i = 0; i < g_token_index; i++)
		ft_printf("[%s] - ", tokens[i]);
	ft_printf("NIL - ");

	ret = check(tokens[0], tokens, count);
	ret ? ft_printf("\033[1;32mOK\033[0m\n") : 0;
	!ret ? ft_printf("\033[1;31mFAIL\033[0m\n") : 0;
	if (!ret)
	{
		ft_dprintf(2, "\033[1;31m%s\033[0m\n", g_errno);
		g_leave = 1;
	}
	load_byte_code(tokens);
	ft_tabdel(&tokens);
	g_token_index = 0;
}
