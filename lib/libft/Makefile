# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/14 10:09:44 by eukwon            #+#    #+#              #
#    Updated: 2022/07/16 13:09:16 by eukwon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = -crs

RM = rm
RMFLAG = -rf

INCLUDE_DIR = ./includes

SRC_DIR = ./srcs
SRC = $(addprefix $(SRC_DIR)/, $(SRC_NAME))
SRC_BONUS = $(addprefix $(SRC_DIR)/, $(SRC_NAME_BONUS))
SRC_NAME = \
ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isprint.c \
ft_itoa.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c

SRC_NAME_BONUS = \
ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_NAME_BONUS = $(SRC_NAME_BONUS:.c=.o)
OBJ_DIR = ./objs
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_NAME))
OBJ_BONUS = $(addprefix $(OBJ_DIR)/, $(OBJ_NAME_BONUS))

ifdef WITH_BONUS
	OBJ_FILES = $(OBJ) $(OBJ_BONUS)
else
	OBJ_FILES = $(OBJ)
endif

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	${AR} ${ARFLAGS} $(NAME) $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir $(OBJ_DIR) 2> /dev/null || true
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(INCLUDE_DIR)

bonus :
	make WITH_BONUS=1 all

clean :
	$(RM) $(RMFLAG) $(OBJ_DIR) $(NAME)

fclean : clean
	$(RM) $(RMFLAG) $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re