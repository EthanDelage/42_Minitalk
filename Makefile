# **************************************************************************** #
#                                                                              # #                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 16:54:01 by edelage           #+#    #+#              #
#    Updated: 2022/11/19 00:43:45 by edelage          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ***********************
#	Folders
# ***********************

OBJ_DIR = 			.objs/

INC_DIR =			./

# ***********************
#	Files
# ***********************

SRC_CLIENT =		ft_client.c

SRC_SERV =			ft_server.c

SRC =				ft_put.c \
					ft_atoi.c \
					ft_join_char.c \

OBJ_CLIENT =		$(addprefix $(OBJ_DIR), $(SRC_CLIENT:.c=.o))

OBJ_SERV =			$(addprefix $(OBJ_DIR), $(SRC_SERV:.c=.o))

OBJ =				$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

HEADER =			minitalk.h

CLIENT =			client

SERV =				server

NAME =				minitalk

# ***********************
#	Compilations
# ***********************

FLAGS =				-Wall -Werror -Wextra

# ***********************
#	Commands
# ***********************

MKDIR =				mkdir -p

# ***********************
#	Rules
# ***********************

all:				$(NAME)

$(NAME):			
					$(MAKE) $(SERV)
					$(MAKE) $(CLIENT)

$(SERV):			$(OBJ_DIR) $(OBJ_SERV) $(OBJ)
					$(CC) $(FLAGS) $(OBJ_SERV) $(OBJ) -o $@

$(CLIENT):			$(OBJ_DIR) $(OBJ_CLIENT)
					$(CC) $(FLAGS) $(OBJ_CLIENT) $(OBJ) -o $@

$(OBJ_DIR)%.o:		%.c $(HEADER) Makefile
					$(CC) $(FLAGS) -I. -c $< -o $@

$(OBJ_DIR):
					$(MKDIR) $(OBJ_DIR)

clean:
					$(RM) $(OBJ) $(OBJ_CLIENT) $(OBJ_SERV)

fclean:				clean
					$(RM) $(CLIENT) $(SERV)

re:					fclean
					$(MAKE) all

.PHONY:				all clean fclean re
