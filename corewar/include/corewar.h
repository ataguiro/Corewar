/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:30:54 by folkowic          #+#    #+#             */
/*   Updated: 2017/05/29 17:41:15 by folkowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <ncurses.h>
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
** MASK pour les options et l 'OCP'
*/
# define DUMP 0x1
# define NB_PLAY 0x2
# define NCURSE 0x4

# define P1_MSK 0xc0
# define P2_MSK 0x30
# define P3_MSK 0xc
# define P1_DIR 0x80
# define P1_IND 0xc0
# define P1_REG 0x40
# define P2_DIR 0x20
# define P2_IND 0x30
# define P2_REG 0x10
# define P3_DIR 0x8
# define P3_IND 0xc
# define P3_REG 0x4
# define TOP_GAME 2
# define LEFT_GAME 3
# define LEN_LINE 64
# define LEN_LINE_CHAR 192

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
# define YELLOW_CURSOR		"\033[33;7m"
# define RED_CURSOR			"\033[31;7m"
# define CYAN_CURSOR		"\033[36;7m"
# define GREY_CURSOR		"\033[100;2m"

# define BORDER				"\033[32;7m"
# define COLOR_GRAY			8
# define CURSOR_GREEN		11

# define PLAYER_1			1
# define PLAYER_2			2
# define PLAYER_3			3
# define PLAYER_4			4
# define PLAYER_0			5
# define PLAYER_C1			11
# define PLAYER_C2			12
# define PLAYER_C3			13
# define PLAYER_C4			14
# define PLAYER_C0			15

void			vm_fill_player(int argc, char **argv);
bool			vm_ctrl_player(t_player *player);
void 			vm_usage(void);
t_decode	 	*vm_decode_octet(unsigned char oct, unsigned char cut);
void 			vm_replace_int(size_t offset, unsigned int val);
t_player		*vm_lst_new_player(void);
void			vm_lst_add_player(t_player **lst, t_player *n);
t_process		*vm_lst_new_process(void);
void			vm_lst_add_process(t_process **lst, t_process *n);
void			vm_lst_add_cpy(t_process **lst);
void 			vm_get_nbplayer(void);
void			vm_get_opt_player(char **av, int *i);
void			vm_check_conditions(void);
unsigned long	vm_reverse_trame(char *input, size_t len);
void			vm_get_arg(t_decode *args, size_t *curs);
void			vm_color_area(size_t target, size_t len, int num_player);
void 			vm_get_dump(char **av, int *i);
void 			vm_runtime(void);
void			vm_call_instruct(t_process *process);
int				vm_get_param_val(size_t pos, size_t len);
t_header		vm_get_player(char *str);
void			nc_show(void);
void			nc_generate_show(void);
void			nc_show_information(void);
char			*nc_hex(unsigned char n);
void			nc_move_cursor(size_t pc, size_t from);
void			vm_dump_mem(const void *addr, size_t size);
void			vm_signal(int sign);
void			nc_refresh_color(size_t from, size_t len);

/*
** instructions
*/
void			in_live(t_process *proc);
void			in_ld(t_process *proc);
void			in_st(t_process *proc);
void			in_add(t_process *proc);
void			in_sub(t_process *proc);
void			in_and(t_process *proc);
void			in_or(t_process *proc);
void			in_xor(t_process *proc);
void			in_zjmp(t_process *proc);
void			in_ldi(t_process *proc);
void			in_sti(t_process *proc);
void			in_fork(t_process *proc);
void			in_lld(t_process *proc);
void			in_lldi(t_process *proc);
void			in_lfork(t_process *proc);
void			in_aff(t_process *proc);

/*
** debug/diagnostic programme
*/
void			db_show_lst(t_player *player);
char			*db_show_map(void);
void			db_show_reg(t_process *process);

#endif
