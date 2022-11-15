# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 16:54:01 by edelage           #+#    #+#              #
#    Updated: 2022/11/15 17:11:28 by edelage          ###   ########lyon.fr    #
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

OBJ_CLIENT =		$(addprefix $(OBJ_DIR), $(SRC_CLIENT:.c=.o))

OBJ_SERV =			$(addprefix $(OBJ_DIR), $(SRC_SERV:.c=.o))

HEADER =			minitalk.h

CLIENT =			client

SERV =				server

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

all:				$(SERV) $(CLIENT)

$(SERV):			$(OBJ_DIR) $(OBJ_SERV)
					$(CC) $(FLAGS) $(OBJ_SERV) -o $@

$(CLIENT):			$(OBJ_DIR) $(OBJ_CLIENT)
					$(CC) $(FLAGS) $(OBJ_CLIENT) -o $@

$(OBJ_DIR)%.o:		%.c $(HEADER) Makefile
					$(CC) $(FLAGS) -I. -c $< -o $@

$(OBJ_DIR):
					$(MKDIR) $(OBJ_DIR)

clean:
					$(RM) $(OBJ_CLIENT) $(OBJ_SERV)

fclean:				clean
					$(RM) $(CLIENT) $(SERV)

re:					fclean
					$(MAKE) all

.PHONY:				all clean fclean re
