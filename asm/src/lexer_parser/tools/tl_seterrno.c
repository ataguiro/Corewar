/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_seterrno.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 12:45:00 by ataguiro          #+#    #+#             */
/*   Updated: 2017/06/28 14:31:23 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	call_ins_errno(char *message, int line)
{
	char	*itoa_line;
	char	*itoa_col;

	itoa_line = ft_itoa(line);
	itoa_col = ft_itoa(1);
	ft_strcpy(g_errno, "asm: ");
	ft_strcat(g_errno, itoa_line);
	ft_strcat(g_errno, ":");
	ft_strcat(g_errno, itoa_col);
	ft_strcat(g_errno, ": ");
	ft_strcat(g_errno, message);
	free(itoa_line);
	free(itoa_col);
}

static void	call_num_errno(char **tokens, int line)
{
	char	*param;
	char	*itoa_line;
	char	*itoa_col;
	int		i;
	int		col;

	i = -1;
	col = 1;
	while (tokens[++i + 1])
		col += ft_strlen(tokens[i]);
	itoa_line = ft_itoa(line);
	itoa_col = ft_itoa(col);
	param = tokens[i];
	ft_strcpy(g_errno, "asm: ");
	ft_strcat(g_errno, itoa_line);
	ft_strcat(g_errno, ":");
	ft_strcat(g_errno, itoa_col);
	ft_strcat(g_errno, " at ");
	ft_strcat(g_errno, param);
	ft_strcat(g_errno, ": ");
	ft_strcat(g_errno, "wrong number of arguments");
	free(itoa_line);
	free(itoa_col);
}

static void	call_par_errno(char *tmp, int line, char **tokens)
{
	char	*itoa_line;
	char	*itoa_col;
	int		i;
	int		col;

	i = -1;
	col = 1;
	while (ft_strcmp(tokens[++i], tmp))
		col += ft_strlen(tokens[i]);
	itoa_line = ft_itoa(line);
	itoa_col = ft_itoa(col);
	ft_strcpy(g_errno, "asm: ");
	ft_strcat(g_errno, itoa_line);
	ft_strcat(g_errno, ":");
	ft_strcat(g_errno, itoa_col);
	ft_strcat(g_errno, " at argument ");
	ft_strcat(g_errno, tmp);
	ft_strcat(g_errno, ": ");
	ft_strcat(g_errno, "wrong argument type");
	free(itoa_line);
	free(itoa_col);
}

void		tl_seterrno(char *message, char **tokens, int line, int type)
{
	if (type == INS_ERROR)
		call_ins_errno(message, line);
	if (type == NUM_ERROR)
		call_num_errno(tokens, line);
	if (type == PAR_ERROR)
		call_par_errno(message, line, tokens);
}
