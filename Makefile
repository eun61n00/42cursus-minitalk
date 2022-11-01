# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 17:08:28 by eukwon            #+#    #+#              #
#    Updated: 2022/11/01 14:51:30 by eukwon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CC = cc
CFLAG = -Wall -Wextra -Werror -g

AR = ar
ARFLAG = -crs

RM = rm
RMFLAG = -rf

INCLUDES_DIR = ./includes
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

# libft
LIBFT = libft.a
LIBFT_DIR = ./lib/libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)
LIBFT_FLAGS = -L $(LIBFT_DIR) -lft
LIBFT_INC_DIR = $(LIBFT_DIR)/includes

# color
NO_COLOR = \e[0m
LIGHT_GREEN = \e[1;32;189;147;249m
GREEN = \e[0;32;189;147;249m
LIGHT_GRAY = \e[1;32;255;121;198
LF = \e[1K\r$(NO_COLOR)
CRLF = \n$(LF)

SRCS = $(addprefix $(SRCS_DIR)/, \
	client.c\
	server.c\
)

OBJS = ./objs/client.o ./objs/server.o

all : $(SERVER) $(CLIENT)

$(SERVER) : $(OBJS)
	$(MAKE) -C ./lib/libft all
	@printf "$(LF)$(LIGHT_GREEN)Successfully Created $(GREEN)$(SERVER)'s Object files!"
	@printf "$(CRLF)$(LIGHT_GREEN)Archiving! $(GREEN)$@${CRLF}"
	$(CC) $(CFLAG) ./objs/server.o $(LIBFT_DIR)/$(LIBFT) -I $(INCLUDES_DIR) $(LIBFT_FLAGS) -o $(SERVER)
	@printf "$(LF)$(LIGHT_GREEN)Successfully Archived $(GREEN)$@$(LIGHT_GREEN)!${CRLF}"

$(CLIENT) : $(OBJS)
	@printf "$(LF)$(LIGHT_GREEN)Successfully Created $(GREEN)$(CLIENT)'s Object files!"
	@printf "$(CRLF)$(LIGHT_GREEN)Archiving! $(GREEN)$@${CRLF}"
	$(CC) $(CFLAG) ./objs/client.o $(LIBFT_DIR)/$(LIBFT) -I $(INCLUDES_DIR) $(LIBFT_FLAGS) -o $(CLIENT)
	@printf "$(LF)$(LIGHT_GREEN)Successfully Archived $(GREEN)$@$(LIGHT_GREEN)!${CRLF}"

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAG) -c $^ -o $@ -I $(INCLUDES_DIR) -I $(LIBFT_INC_DIR)
	@printf "$(LF)$(LIGHT_GREEN)Create $(GREEN)$@ $(LIGHT_GREEN)from $(GREEN)$<${CRLF}"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean :
	@$(MAKE) -C ./lib/libft fclean
	@${RM} $(RMFLAG) $(OBJS_DIR) $(SERVER) $(CLIENT)
	@printf "$(LF)$(LIGHT_GREEN)Cleaning $(GREEN)$(SERVER) and $(CLIENT)'s Object files...${CRLF}"

fclean : clean
	@${RM} $(RMFLAG) $(NAME)
	@printf "$(LF)$(LIGHT_GREEN)Cleaning $(GREEN)$(SERVER) and $(CLIENT)${CRLF}"

re : fclean all

.PHONY : all clean fclean re