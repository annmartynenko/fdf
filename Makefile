#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/03 12:34:05 by amartyne          #+#    #+#              #
#    Updated: 2019/01/03 12:34:09 by amartyne         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =  fdf

SRC = fdf.c read_map.c draw_line.c iso.c make_mass.c rotation.c ft_atoi_base.c \
ft_strlen_chr.c fill_kart.c

HDR = fdf.h get_next_line.h

FLAGS = -Wall -Wextra -Werror

OUT = $(SRC:.c=.o)

all: $(NAME)

%.o:%.c $(HDR)
	gcc $(FLAGS) -o $@ $<

./libft/libft.a:
	make -C libft

$(NAME): $(OUT) ./libft/libft.a
	gcc -o $(NAME) $(FLAGS) -lmlx -framework OpenGL -framework AppKit -L ./libft -lft -lm  $(SRC)

clean:
	make clean -C libft
	/bin/rm -f *.o

fclean: clean
	make fclean -C libft
	/bin/rm -f $(NAME)

re: fclean all