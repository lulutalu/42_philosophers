# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 00:27:49 by lduboulo          #+#    #+#              #
#    Updated: 2022/05/04 18:33:13 by lduboulo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS

GREEN	= \033[1;32m
RED 	= \033[1;31m
ORANGE	= \033[1;33m
GREY	= \033[1;90m
BUILD	= \e[38;5;225m
SEP		= \e[38;5;120m
DUCK	= \e[38;5;227m
RESET	= \033[0m

# COLORS


SRCS_DIR	= ./src/
SRCS_FILES	= ft_atol.c ft_calloc.c ft_bzero.c

SRCS		:= ${patsubst %, ${SRCS_DIR}%, ${SRCS_FILES}}


O_DIR		= ./objs/

OBJS_FILES	:= ${SRCS_FILES:.c=.o}
OBJS		:= ${patsubst %, ${O_DIR}%, ${OBJS_FILES}}

HEADS_DIR	= ./../includes/

NAME		= libutils.a

MAKELIB		= ${MAKE} -C
CC			= gcc
AR			= ar rcs
MKDIR		= mkdir
RM			= rm -rf

CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address

TSEP		= ${SEP}=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=${RESET}


all:		${NAME}

${NAME}:	${O_DIR} ${OBJS}
			@printf "\n${TSEP}\n"
			@printf "${GREEN} 💻 Successfully compiled ${NAME} .o's${RESET} ✅\n"
			@${AR} ${NAME} ${OBJS}
			@printf "${GREEN} 💻 Successfully created ${NAME} library${RESET} ✅\n"

${O_DIR}:
			@${MKDIR} ${O_DIR}

${O_DIR}%.o:${SRCS_DIR}%.c
			@${CC} ${CFLAGS} -I${HEADS_DIR} -o $@ -c $<
			@printf "\e[1K\r${BUILD} 🚧 $@ from $<${RESET}"

clean :
			@${RM} ${O_DIR}
			@printf "${RED} 🧹 Deleted ${NAME} .o's${RESET} ❌\n"
			@printf "${RED}=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-${RESET}\n"

fclean : clean
			@${RM} ${NAME}
			@printf "${RED} 💥 Deleted ${NAME} files${RESET} ❌\n"

re : fclean all

norm :
			@printf "${DUCK} 🐥 Checking Norm for ${NAME}${RESET}\n"
			@norminette ${SRCS}

.PHONY : all clean fclean re norm
