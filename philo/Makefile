# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 18:29:51 by lduboulo          #+#    #+#              #
#    Updated: 2022/04/23 20:05:20 by lduboulo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS

GREEN	= \033[1;32m
RED 	= \033[1;31m
ORANGE	= \033[1;33m
BUILD	= \e[38;5;225m
SEP		= \e[38;5;120m
DUCK	= \e[38;5;227m
RESET	= \033[0m

# COLORS


SRCS_DIR		= ./src/
SRCS_FILES		= main.c

SRCS			:= ${patsubst %, ${SRCS_DIR}%, ${SRCS_FILES}}

O_DIR			= ./objs/

OBJS_FILES		:= ${SRCS_FILES:.c=.o}

OBJS			:= ${patsubst %, ${O_DIR}%, ${OBJS_FILES}}

HEADS_DIR		= ./includes/

NAME			= philo


LIBUTILS		= ./utils/


MAKELIB			= ${MAKE} -C
CC				= gcc
AR				= ar rcs
MKDIR			= mkdir
RM				= rm -rf

CFLAGS			= -Wall -Wextra -Werror -g3 -fsanitize=address -pthread

TSEP			= ${SEP}=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=${RESET}



all:			${NAME}

${NAME}:		${O_DIR} ${OBJS}
				@printf "\n"
				@printf "${TSEP}\n"
				@printf "\n${GREEN} 💻 Successfully compiled ${NAME} .o's${RESET} ✅\n"
				@${CC} ${CFLAGS} -o ${NAME} ${OBJS}
				@printf "${GREEN} 💻 Successfully created ${NAME} executable${RESET} ✅\n"
				@printf "\n${TSEP}\n"

${O_DIR}:
				@${MKDIR} ${O_DIR}
				@printf "${BUILD}${O_DIR} Directory Created 📎${RESET}\n\n"

${O_DIR}%.o:${SRCS_DIR}%.c
				@${CC} ${CFLAGS} -I${HEADS_DIR} -o $@ -c $<
				@printf "\e[1K\r${BUILD} 🚧 $@ from $<${RESET}"

clean :
				@${RM} ${O_DIR}
				@printf "\n${RED} 🧹 Deleted ${NAME} .o's${RESET} ❌\n\n"

fclean : 		clean
				@${RM} ${NAME} ${NAME}.dSYM
				@${MAKELIB} ${LIBUTILS} fclean
				@printf "${RED} 💥 Deleted ${NAME} files${RESET} ❌\n\n"

re : 			fclean all

norm :
				@${MAKELIB} ${LIBUTILS} norm
				@printf "${DUCK} 🐥 Checking Norm for ${NAME}${RESET}\n"
				@norminette ${SRCS}
				@norminette ${HEADS_DIR}

.PHONY : all clean fclean re norm
