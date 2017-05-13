/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 18:55:29 by ataguiro          #+#    #+#             */
/*   Updated: 2017/05/13 14:32:12 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <sys/types.h>
# include <fcntl.h>

# include "libft.h"

# define OPT_A				0b00000001
# define OPT_H				0b00000010

# define ISON(options, opt)	(options & opt)

/*
**	OP_H DATA (Grammar)
*/

# define IND_SIZE			2
# define REG_SIZE			4
# define DIR_SIZE			REG_SIZE

# define REG_CODE			1
# define DIR_CODE			2
# define IND_CODE			3


# define MAX_ARGS_NUMBER	4
# define MAX_PLAYERS		4
# define MEM_SIZE			(4 * 1024)
# define IDX_MOD			(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE		(MEM_SIZE / 6)

# define COMMENT_CHAR		'#'
# define LABEL_CHAR			':'
# define DIRECT_CHAR		'%'
# define SEPARATOR_CHAR		','

# define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"

# define REG_NUMBER			16

# define CYCLE_TO_DIE		1536
# define CYCLE_DELTA		50
# define NBR_LIVE			21
# define MAX_CHECKS			10

# define T_REG				1
# define T_DIR				2
# define T_IND				4
# define T_LAB				8

/*
**	Building header
*/

# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"

# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)
# define COREWAR_EXEC_MAGIC	0xea83f3

/*
**	Automaton states
*/

# define INS 0
# define ARGS 1

typedef struct				s_header
{
	unsigned int			magic;
	char					prog_name[PROG_NAME_LENGTH + 1];
	unsigned int			prog_size;
	char					comment[COMMENT_LENGTH + 1];
}							t_header;

/*
**	Recovering offsets while first read for prog_size and zjump
*/

typedef struct				s_offset
{
	char					*label_name;
	int						offset;
}							t_offset;

/*
**	Structures to build g_optab[17]
*/

typedef struct				s_op
{
	char					ins_name[7];
	int						max_arg;
	int						arg_type[3];
	int						opcode;
	int						cycle;
	char					desc[128];
	int						unk;
	int						unk2;
}							t_op;

/*
**	Exported global variables
*/

extern int					g_offset_index;
extern t_offset				g_offtab[256];
extern t_op					g_optab[17];

extern int					g_state;
extern int					g_load[14];
extern int					g_token_index;

/*
**	Parsing options
*/

char						get_options(char **av);

/*
**	Errors
*/

void						fatal_error(void);

/*
**	Lexer_Parser
*/

void						main_lexer(char *src_file);
void						lex_get_offset(int fd);
int							size_of_line(char **tokens);
void						lexical_analyse(int fd);
void						token_parser(char **tokens);

/*
**	Tools for Lexer_parser
*/

int							tl_frontsearch(char **tokens, char **split, \
																int i, int j);
int							tl_backsearch(char **tokens, char **split, \
																int i, int j);
int							tl_islabel(char *subject);
int							tl_islabel_call(char *subject);
int							tl_isinstruction(char *subject);
int							tl_isregister(char *subject);
int							tl_isdirect(char *subject);
int							tl_isindex(char	*subject);

#endif
