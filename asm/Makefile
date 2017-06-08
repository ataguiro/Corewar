# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: folkowic <folkowic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/15 14:57:28 by ataguiro          #+#    #+#              #
#    Updated: 2017/06/08 11:17:57 by folkowic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Editable =====
NAME	:=	asm
INDEX	:=	1
# ====================

# ===== Standard =====
CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror -g  #-fsanitize=address
SRCDIR	:=	src/
OBJDIR	:=	obj/
INCDIR	:=	include/
LIBDIR	:=	../libft/
SRC		:=	$(SRCDIR)asm.c \
			$(SRCDIR)options.c \
			$(SRCDIR)error.c \
			$(SRCDIR)lexer_parser/main_lexer.c \
			$(SRCDIR)lexer_parser/op_code.c \
			$(SRCDIR)lexer_parser/tools/tl_islabel.c \
			$(SRCDIR)lexer_parser/tools/tl_islabel_call.c \
			$(SRCDIR)lexer_parser/tools/tl_isinstruction.c \
			$(SRCDIR)lexer_parser/tools/tl_isbyte_instruction.c \
			$(SRCDIR)lexer_parser/tools/tl_isregister.c \
			$(SRCDIR)lexer_parser/tools/tl_isdirect.c \
			$(SRCDIR)lexer_parser/tools/tl_isindex.c \
			$(SRCDIR)lexer_parser/tools/tl_frontsearch.c \
			$(SRCDIR)lexer_parser/tools/tl_backsearch.c \
			$(SRCDIR)lexer_parser/tools/tl_bigendian_short.c \
			$(SRCDIR)lexer_parser/tools/tl_bigendian.c \
			$(SRCDIR)lexer_parser/tools/tl_getindex_ins.c \
			$(SRCDIR)lexer_parser/tools/tl_seterrno.c \
			$(SRCDIR)lexer_parser/tools/tl_dir_translate.c \
			$(SRCDIR)lexer_parser/tools/tl_reg_translate.c \
			$(SRCDIR)lexer_parser/tools/tl_ind_translate.c \
			$(SRCDIR)lexer_parser/tools/tl_ocp_translate.c \
			$(SRCDIR)lexer_parser/lexical_analyse.c \
			$(SRCDIR)lexer_parser/size_of_line.c \
			$(SRCDIR)lexer_parser/token_parser.c \
			$(SRCDIR)lexer_parser/load_byte_code.c \
			$(SRCDIR)lexer_parser/write_byte_code.c \
			$(SRCDIR)lexer_parser/write_excl.c \
			$(SRCDIR)lexer_parser/write_no_excl.c \
			$(SRCDIR)lexer_parser/lex_get_offset.c
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
	$(CC) $(CFLAGS)  $(OBJ) -o $@ $(LIBPATH) $(LIB) $(INC)
	echo "\033[1;32m" "\n✓ $@ ok ;)" "\033[0m"

$(OBJDIR)%.o: $(SRCDIR)%.c $(CACHEF)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	printf "\r"
	printf $(BGREEN)"[ compiling $(NAME)... ] "
	printf "$(shell echo 'scale=2;$(INDEX)/30 * 100' | bc)%%"$(EOC)
	$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

$(CACHEF):
	test -d $(OBJDIR) || mkdir $(OBJDIR)
	test -d $(OBJDIR)lexer_parser || mkdir $(OBJDIR)lexer_parser
	test -d $(OBJDIR)lexer_parser/tools || mkdir $(OBJDIR)lexer_parser/tools
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
