# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 22:47:08 by lutsiara          #+#    #+#              #
#    Updated: 2020/02/18 22:48:46 by lutsiara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft/
VM = vm/
ASM = asm/

LIBFT = libft/libft.a

export LIBFT

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
