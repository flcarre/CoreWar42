# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 22:47:08 by lutsiara          #+#    #+#              #
#    Updated: 2020/05/15 21:37:07 by lutsiara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft/
LIBPRINTF = ft_printf/
VM = vm/
ASM = asm.d/

LIBFT = libft/libft.a
FTPRINTF = ft_printf/libftprintf.a
INC_LIB_PATH = libft/includes/

export LIBFT
export FTPRINTF
export INC_LIB_PATH

all:
	@make -C $(LIBPRINTF)
	@make -C $(LIB)
	@make -C $(ASM)
	@make -C $(VM)

clean:
	@make -C $(LIBPRINTF) clean
	@make -C $(LIB) clean
	@make -C $(ASM) clean
	@make -C $(VM) clean

fclean:
	@make -C $(LIBPRINTF) fclean
	@make -C $(LIB) fclean
	@make -C $(ASM) fclean
	@make -C $(VM) fclean

lib:
	@make -C $(LIBPRINTF)
	@make -C $(LIB)

vm:
	@make -C $(LIBPRINTF)
	@make -C $(LIB)
	@make -C $(VM)

asm:
	@make -C $(LIBPRINTF)
	@make -C $(LIB)
	@make -C $(ASM)

re: fclean all

.PHONY: all clean fclean lib vm asm re

.NOTPARALLEL: re
