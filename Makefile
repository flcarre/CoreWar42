# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 22:47:08 by lutsiara          #+#    #+#              #
#    Updated: 2020/02/19 16:30:38 by lutsiara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft/
VM = vm/
ASM = asm.d/

LIBFT = libft/libft.a
INC_LIB_PATH = libft/includes/

export LIBFT
export INC_LIB_PATH

all:
	@make -C $(LIB)
	@make -C $(ASM)
	@make -C $(VM)

clean:
	@make -C $(LIB) clean
	@make -C $(ASM) clean
	@make -C $(VM) clean

fclean: clean
	@make -C $(LIB) fclean
	@make -C $(ASM) fclean
	@make -C $(VM) fclean

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: re
