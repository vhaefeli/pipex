# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 13:10:08 by vhaefeli          #+#    #+#              #
#    Updated: 2022/06/20 14:36:46 by vhaefeli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS 			= -Wall -Wextra -Werror -g #-fsanitize=address -fno-omit-frame-pointer
TARGET 			= pipex
SRCS_DIR 		= ./src
OBJS_DIR 		= ./obj
_SRCS 			= pipex.c
					

OBJS 			= $(patsubst %.c, $(OBJS_DIR)/%.o, $(_SRCS))
SRCS 			= $(patsubst %, $(SRCS_DIR)/%, $(_SRCS))

.PHONY : all clean fclean re bonus test

all: $(TARGET)

clean:
	rm -f $(OBJS)
	rm -df $(OBJS_DIR)


fclean: clean
	rm -f $(TARGET)

re: fclean all

$(OBJS_DIR):
	@mkdir -p $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) -c $(CFLAGS) -o $@ $^ $(INCLUDES)

$(TARGET):  $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o

$(MINILIBX_DIR)/libmlx.a:
	$(MAKE) -sC $(MINILIBX_DIR)

$(LIBFT_DIR)/libft.a:
	$(MAKE) -sC $(LIBFT_DIR) bonus

bonus: $(TARGET)



