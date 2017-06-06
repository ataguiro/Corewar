# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/15 14:57:28 by ataguiro          #+#    #+#              #
#    Updated: 2017/06/06 18:15:39 by folkowic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Editable =====
NAME	:=	corewar
INDEX	:=	1
# ====================

# ===== Standard =====
CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror -g #-fsanitize=address
SRCDIR	:=	src/
OBJDIR	:=	obj/
INCDIR	:=	include/
LIBDIR	:=	../libft/
SRC_FILE:=	\
corewar.c\
virtual_machine/vm_get_player.c\
virtual_machine/vm_fill_player.c\
virtual_machine/vm_ctrl_player.c\
virtual_machine/vm_runtime.c\
virtual_machine/vm_decode_octet.c\
virtual_machine/vm_call_instruct.c\
virtual_machine/vm_check_conditions.c\
virtual_machine/vm_reverse_trame.c\
virtual_machine/vm_get_arg.c\
virtual_machine/vm_lst_add_player.c\
virtual_machine/vm_lst_new_player.c\
virtual_machine/vm_lst_add_process.c\
virtual_machine/vm_lst_new_process.c\
virtual_machine/vm_lst_add_cpy.c\
virtual_machine/vm_get_nbplayer.c\
virtual_machine/vm_get_param_val.c\
virtual_machine/vm_usage.c\
virtual_machine/vm_get_dump.c\
virtual_machine/vm_get_opt_player.c\
virtual_machine/vm_replace_int.c\
virtual_machine/vm_color_area.c\
virtual_machine/vm_dump_mem.c\
virtual_machine/vm_default_mode.c\
virtual_machine/vm_check_length.c\
instruct/in_live.c\
instruct/in_ld.c\
instruct/in_st.c\
instruct/in_add.c\
instruct/in_sub.c\
instruct/in_and.c\
instruct/in_or.c\
instruct/in_xor.c\
instruct/in_zjmp.c\
instruct/in_ldi.c\
instruct/in_sti.c\
instruct/in_fork.c\
instruct/in_lld.c\
instruct/in_lldi.c\
instruct/in_lfork.c\
instruct/in_aff.c\
server/se_check.c \
server/se_secure.c \
server/se_fatal.c \
server/se_handle.c \
server/se_search_slot.c \
server/se_sendinfo.c \
server/se_accept_thread.c \
server/se_accept_players.c \
server/se_get.c\
ncurses/nc_resize_win.c \
ncurses/nc_lst_new_blk.c\
ncurses/nc_lst_add_blk.c\
ncurses/nc_blink_live.c\
ncurses/nc_lst_rm_blk.c\
ncurses/nc_lst_place_blk.c\
ncurses/nc_blink_st.c\
ncurses/nc_show.c\
ncurses/nc_generate_show.c\
ncurses/nc_show_information.c\
ncurses/nc_hex.c\
ncurses/nc_move_cursor.c\
ncurses/nc_refresh_color.c\
ncurses/nc_dlc_win.c\
ncurses/nc_std_conf.c

SRC = $(addprefix $(SRCDIR)/, $(SRC_FILE))
OBJ		:=	$(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
INC		:=	-I./$(INCDIR) -I./$(LIBDIR)$(INCDIR)
LIBPATH	:=	-L./$(LIBDIR) -lft
CACHEF	:=	.cache_exists
# ====================

# ====== Colors ======
CLEAR		= "\033[2K"
UP			= "\033[A"
EOC			= "\033[0;0m"
BLACK		= "\033[0;30m"
RED			= "\033[0;31m"
BRED		= "\033[1;31m"
GREEN		= "\033[0;32m"
BGREEN		= "\033[1;32m"
YELLOW		= "\033[0;33m"
BLUE		= "\033[0;34m"
PURPLE		= "\033[0;35m"
CYAN		= "\033[0;36m"
WHITE		= "\033[0;37m"
# ====================

.PHONY: all libft norme clean fclean re
.SILENT:

all: $(NAME)

$(NAME): libft $(OBJ)
	$(CC) $(CFLAGS)  $(OBJ) -o $@ $(LIBPATH) $(LIB) $(INC) -lncurses
	echo "\033[1;32m" "\n✓ $@ ok ;)" "\033[0m"

$(OBJDIR)%.o: $(SRCDIR)%.c $(CACHEF)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	printf "\r"
	printf $(BGREEN)"[ compiling $(NAME)... ] "
	printf "$(shell echo 'scale=2;$(INDEX)/59 * 100' | bc)%%"$(EOC)
	$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

$(CACHEF):
	test -d $(OBJDIR) || mkdir $(OBJDIR)
	test -d $(OBJDIR)server || mkdir $(OBJDIR)server
	test -d $(OBJDIR)ncurses || mkdir $(OBJDIR)ncurses
	test -d $(OBJDIR)instruct || mkdir $(OBJDIR)instruct
	test -d $(OBJDIR)virtual_machine || mkdir $(OBJDIR)virtual_machine
	test -d $(OBJDIR)debug || mkdir $(OBJDIR)debug
	test -d $(CACHEF) || touch $(CACHEF)

%.c:
	printf $(RED)"Missing file : $@\n"$(EOC)

libft:
	make -C $(LIBDIR)

norme:
	norminette $(SRCDIR) $(INCDIR) | grep -v Norme -B1 || true
	norminette $(LIBFT)$(SRCDIR) $(LIBFT)$(INCDIR) | grep -v Norme -B1 || true

clean:
	make -C $(LIBDIR) clean
	rm -rf $(OBJDIR) $(CACHEF)
	printf $(YELLOW)"All objects removed\n"$(EOC)

fclean: clean
	make -C $(LIBDIR) fclean
	rm -f $(NAME)
	printf $(RED)"$(NAME) removed\n"$(EOC)

re: fclean all
