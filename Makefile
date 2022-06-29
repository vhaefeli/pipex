# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 13:10:08 by vhaefeli          #+#    #+#              #
#    Updated: 2022/06/29 13:54:58 by vhaefeli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS 			= -Wall -Wextra -Werror -g #-fsanitize=address -fno-omit-frame-pointer
TARGET 			= pipex
SRCS_DIR 		= ./src
OBJS_DIR 		= ./obj
INCLUDES_DIRS	= ./includes
INCLUDES		= $(addprefix -I,$(INCLUDES_DIRS))
_SRCS			= ft_printf.c\
					ft_split.c\
					ft_strjoin.c\
					ft_strlcpy.c\
					ft_strlen.c\
					ft_strnstr.c\
					ft_substr.c\
					list_cmd.c\
					listmanip.c\
					pipex.c\
					pipex_children_process.c\
					pipex_utils.c

OBJS 			= $(patsubst %.c, $(OBJS_DIR)/%.o, $(_SRCS))
SRCS 			= $(patsubst %, $(SRCS_DIR)/%, $(_SRCS))

.PHONY : all clean fclean re bonus test norminette

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

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INCLUDES)


bonus: $(TARGET)

norminette:
	@norminette $(SRCS_DIR) $(INCLUDES_DIRS)



