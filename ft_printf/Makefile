# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 19:43:10 by wahasni           #+#    #+#              #
#    Updated: 2020/05/16 16:30:28 by lutsiara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = @cc -O3
CFLAGS = -Wall -Wextra -Werror -Iincludes

SRCDIR = srcs/

UTILSDIR = utils/

CONVDIR = conv/

INCDIR = includes/

H_FILENAME = ft_printf.h

H_FILES = $(addprefix $(INCDIR), $(H_FILENAME))

UTILS = $(UTILSDIR)ft_atoip.c \
		$(UTILSDIR)ft_bzero.c \
		$(UTILSDIR)ft_lltoa_base.c \
		$(UTILSDIR)ft_memcpy.c \
		$(UTILSDIR)ft_memset.c \
		$(UTILSDIR)ft_putstr_fd.c \
		$(UTILSDIR)ft_strcpy.c \
		$(UTILSDIR)ft_strlenp.c \
		$(UTILSDIR)ft_strnequ.c \
		$(UTILSDIR)ft_wchar.c \
		$(UTILSDIR)ft_str_toupper.c \
		$(UTILSDIR)options.c \
		$(UTILSDIR)maths.c

UTIOBJ = $(UTILS:.c=.o)

CONV = $(CONVDIR)c_arg.c \
	   $(CONVDIR)dou_arg.c \
	   $(CONVDIR)int_arg.c \
	   $(CONVDIR)p_arg.c \
	   $(CONVDIR)f_arg.c \
	   $(CONVDIR)f_conv.c \
	   $(CONVDIR)pct_arg.c \
	   $(CONVDIR)s_arg.c \
	   $(CONVDIR)d_conv.c \
	   $(CONVDIR)u_conv.c \
	   $(CONVDIR)o_conv.c \
	   $(CONVDIR)x_conv.c \
	   $(CONVDIR)not_conv.c \
	   $(CONVDIR)man_arg.c \
	   $(CONVDIR)cast.c

CONVOBJ = $(CONV:.c=.o)

SRCS = $(SRCDIR)ft_printf.c \
	   $(SRCDIR)handle_buff.c \
	   $(SRCDIR)manage_conv.c \
	   $(SRCDIR)manage_colors.c \
	   $(SRCDIR)options_padding.c \
	   $(SRCDIR)options_check.c \
	   $(SRCDIR)parse_arg.c

OBJ = $(SRCS:.c=.o)

BLUE = "\\033[36m"
RED = "\\033[31m"
WHITE = "\\033[0m"
GREEN = "\\033[32m"

EOLCLR = "\\033[0K"
CHECK = "✓"
OK = "$(CHECK)$(WHITE)"

$(NAME): $(OBJ) $(UTIOBJ) $(CONVOBJ) $(H_FILES)
	@ar rc $(NAME) $(OBJ) $(UTIOBJ) $(CONVOBJ)
	@ranlib $(NAME)
	@printf "\r$(EOLCLR)$(NAME): $(GREEN)$(OK)\n"

all: $(NAME)

%.o: %.c
	@printf "\r$(EOLCLR)$(NAME): $< $(BLUE)$(OK)"
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@printf "$(NAME): rm *.o"
	@rm -rf $(OBJ) $(UTIOBJ) $(CONVOBJ)
	@printf " $(RED)$(OK)\n"

fclean: clean
	@printf "$(NAME): rm $(NAME)"
	@rm -f $(NAME)
	@printf " $(RED)$(OK)\n"

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: re
