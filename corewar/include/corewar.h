/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_machine.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:30:54 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/15 12:07:15 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft.h"
# include "op.h"
# include "struct.h"
# define BUF_SIZE			4096
# define LEN_MAGIC			sizeof(int)
# define LEN_PROG_SIZE		sizeof(long)
# define OFFSET_PROG_NAME	LEN_MAGIC
# define OFFSET_PROG_SIZE	OFFSET_PROG_NAME + PROG_NAME_LENGTH
# define OFFSET_COMMENT		OFFSET_PROG_SIZE + LEN_PROG_SIZE
# define OFFSET_MAP			OFFSET_COMMENT + COMMENT_LENGTH + LEN_MAGIC

/*
** MASK pour les options
*/
# define DUMP 0x1
# define NB_PLAY 0x2


/*
** Color printf
*/
# define DEFAULT			"\033[0m"
# define HIGHLIGHT			"\033[1m"
# define UNDERLINE			"\033[4m"
# define BLINK				"\033[5m"
# define BLACK				"\033[30m"
# define RED				"\033[31m"
# define GREEN				"\033[32m"
# define YELLOW				"\033[33m"
# define BLUE				"\033[34m"
# define PURPLE				"\033[35m"
# define CYAN				"\033[36m"
# define WHITE				"\033[37m"

# define BLACK_LIGHT		"\033[1;30m"
# define RED_LIGHT			"\033[1;31m"
# define GREEN_LIGHT		"\033[1;32m"
# define YELLOW_LIGHT		"\033[1;33m"
# define BLUE_LIGHT			"\033[1;34m"
# define PURPLE_LIGHT		"\033[1;35m"
# define CYAN_LIGHT			"\033[1;36m"
# define WHITE_LIGHT		"\033[1;37m"

# define GREY				"\033[1;30m"
# define GREEN_CURSOR		"\033[32;7m"
# define BLUE_CURSOR		"\033[34;7m"
# define RED_CURSOR			"\033[31;7m"
# define CYAN_CURSOR		"\033[36;7m"
# define GREY_CURSOR		"\033[36;7m"


t_player	*vm_lst_new(void);
void		vm_lst_add(t_player **lst, t_player *n);
void		vm_fill_player(int argc, char **argv);
bool		vm_ctrl_player(t_player *player);
void 		vm_usage(void);
t_decode 	*vm_decode_octet(unsigned char oct);

/*
** vm_get_player.c	
*/
t_header	vm_get_player(char *str);
void 		vm_get_nbplayer(void);

/*
** vm_instruc_tools.c	
*/
int	vm_get_param_val(size_t pos, size_t len);

/*
** instructions
*/
 void in_live(t_player *play);
 void in_ld(t_player *play);
 void vm_st(t_player *play);
 void vm_add(t_player *play);
 void vm_subb(t_player *play);
 void vm_and(t_player *play);
 void vm_or(t_player *play);
 void vm_xor(t_player *play);
 void vm_zjmp(t_player *play);
 void vm_ldi(t_player *play);
 void vm_sti(t_player *play);
 void in_fork(t_player *play);
 void vm_lld(t_player *play);
 void vm_lldi(t_player *play);
 void vm_lfork(t_player *play);
 void vm_aff(t_player *play);
void	vm_check_conditions(void);
unsigned long	vm_reverse_trame(char *input, size_t len);
void	vm_get_arg(t_decode *args, size_t *curs);

/*
** options
*/
void 	get_dump(char **av, int *i);
void 	get_nbplayer(char **av, int *i);

/*
** VM_RUNTIME.c
*/
void 	vm_load_cycles(t_player *play);
void 	vm_init_player_cycles(void);
void 	vm_do_actions(void);
void 	vm_runtime(void);

/*
** vm_instruct_call.c
*/
void 	vm_call_instruct(t_player *player);


/*
** debug/diagnostic programme
*/
void	db_show_lst(t_player *player);
void	db_show_map(void);
void	db_show_reg(t_player *player);

#endif
