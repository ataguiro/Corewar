/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 18:55:29 by ataguiro          #+#    #+#             */
/*   Updated: 2017/04/10 15:46:51 by echo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define OPT_A 0b00000001
# define OPT_H 0b00000010

# define ISON(options, opt) (options & opt)

# include "libft.h"

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
