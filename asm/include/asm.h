/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 18:55:29 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/09 00:19:21 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define OPT_A 0b00000001
# define OPT_H 0b00000010

# define ISON(options, opt) (options & opt)

# include <fcntl.h>

# include "libft.h"

/*
**	Building header
*/

# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct			header_s
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}						header_t;

/*
**	Parsing options
*/

char	get_options(char **av);

/*
**	Errors
*/

void	fatal_error(void);

/*
**	Lexer_Parser
*/

void	main_lexer(char *src_file);

#endif
