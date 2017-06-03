# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/15 14:57:28 by ataguiro          #+#    #+#              #
#    Updated: 2017/06/03 14:21:53 by folkowic         ###   ########.fr        #
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
vm_get_player.c\
vm_fill_player.c\
db_show_lst.c\
vm_ctrl_player.c\
db_show_map.c\
vm_runtime.c\
vm_decode_octet.c\
vm_call_instruct.c\
vm_check_conditions.c\
vm_reverse_trame.c\
in_live.c\
in_ld.c\
in_st.c\
in_add.c\
in_sub.c\
in_and.c\
in_or.c\
in_xor.c\
in_zjmp.c\
in_ldi.c\
in_sti.c\
in_fork.c\
in_lld.c\
in_lldi.c\
in_lfork.c\
in_aff.c\
db_show_reg.c\
vm_get_arg.c\
vm_lst_add_player.c\
vm_lst_new_player.c\
vm_lst_add_process.c\
vm_lst_new_process.c\
vm_lst_add_cpy.c\
vm_get_nbplayer.c\
vm_get_param_val.c\
vm_usage.c\
vm_get_dump.c\
vm_get_opt_player.c\
vm_replace_int.c\
vm_color_area.c\
vm_dump_mem.c\
nc_show.c\
nc_generate_show.c\
nc_show_information.c\
nc_hex.c\
nc_move_cursor.c\
nc_refresh_color.c\
nc_dlc_win.c\
nc_std_conf.c\
vm_default_mode.c\
nc_resize_win.c \
server/se_check.c \
server/se_fatal.c \
server/se_accept_players.c \
server/se_get.c\
nc_lst_new_blk.c\
nc_lst_add_blk.c\
nc_blink.c\
nc_lst_rm_blk.c

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
