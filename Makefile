SRCS_MAIN		=	srcs/pipex/pipex.c

SRCS_PIPEX		=	srcs/exec_pipex/children_work.c			\


SRCS_PARSING		=	srcs/parsing/parsing.c		\


SRCS_UTILS		=		srcs/utils/pipex_utils.c	\


SRCS_INIT		=		srcs/init/init_pipex.c	\

SRCS_CLEAN		=		srcs/clean/cleaner_prog.c

#SRCS_BONUS		=		srcs/bonus/pipex_bonus.c	\

HEADER_FILES	=	libft.h					\
					define.h				\
					fonctions.h				\
					includes.h


#PIPEX_BONUS			=	pipex_bonus

NAME			= 	pipex

OBJS_MAIN 		= 	${SRCS_MAIN:.c=.o}

OBJS_PIPEX 		= 	${SRCS_PIPEX:.c=.o}

OBJS_SWAP 		= 	${SRCS_PARSING:.c=.o}

OBJS_UTILS		=	${SRCS_UTILS:.c=.o}

OBJS_INIT		=	${SRCS_INIT:.c=.o}

OBJS_CLEAN		=	${SRCS_CLEAN:.c=.o}

OBJS_PARSING	=	${SRCS_PARSING:.c=.o}

#OBJS_BONUS		=	${SRCS_BONUS:.c=.o}

DEPS_FILES		=	${SRCS_MAIN:.c=.d} ${SRCS_PIPEX:.c=.d} ${SRCS_PARSING:.c=.d} ${SRCS_UTILS:.c=.d} ${SRCS_INIT:.c=.d} ${SRCS_CLEAN:.c=.d}

INCS			=	-I ./includes -I libft/includes/

LIBFT			=	libft/libft.a

CC				=	gcc 

CFLAGS			=  -Wall -Werror -Wextra

RM				=	rm -rf

_END=$'\e[0m
_BOLD=$'\e[1m
_UNDER=$'\e[4m
_REV=$'\e[7m

_GREY=$'\e[30m
_RED=$'\e[0;31m
_GREEN=$'\e[32m
_YELLOW=$'\e[33m
_BLUE=$'\e[34m
_PURPLE=$'\e[35m
_CYAN=$'\e[36m
_WHITE=$'\e[37m

_IGREY=$'\e[40m
_IRED=$'\e[41m
_IGREEN=$'\e[42m
_IYELLOW=$'\e[43m
_IBLUE=$'\e[44m
_IPURPLE=$'\e[45m
_ICYAN=$'\e[46m
_IWHITE=$'\e[47m

all:		${NAME}

.c.o:
				@echo "Compiling ${_YELLOW}${_BOLD}$<${_END}..."
				@${CC} ${CFLAGS} ${INCS} -MMD -c $< -o $@ ${INCS}

${NAME}:		${OBJS_MAIN} ${OBJS_PIPEX} ${OBJS_PARSING} ${OBJS_UTILS} ${OBJS_INIT} ${OBJS_CLEAN}
				@echo "Compiling ${_GREEN}${_BOLD}libft${_END}..."
				@${MAKE} -C libft >/dev/null
				@echo "Compiling ${_CYAN}${_BOLD}pipex${_END}..."
				@${CC} ${CFLAGS} ${INCS} ${OBJS_MAIN} ${OBJS_UTILS} ${OBJS_PARSING} ${OBJS_PIPEX} ${OBJS_INIT} ${OBJS_CLEAN} -o ${NAME} ${LIBFT}

#${PIPEX_BONUS}	:	${OBJS_CHECK} ${OBJS_SWAP} ${OBJS_PIPEX} ${OBJS_ALGO} ${OBJS_UTILS}
#				@echo "Compiling ${_GREEN}${_BOLD}libft${_END}..."
#				@${MAKE} -C libft >/dev/null
#				@echo "Compiling ${_CYAN}${_BOLD}checker${_END}..."
#				@${CC} ${CFLAGS} ${INCS} ${OBJS_CHECK} ${OBJS_SWAP} ${OBJS_PIPEX} ${OBJS_ALGO} ${OBJS_UTILS} -o ${CHECKER} ${LIBFT}

#bonus		:	${CHECKER}

clean:
				@echo "Deleting ${_RED}${_BOLD}binary files${_END}..."
				@${RM} ${OBJS_MAIN} ${OBJS_PIPEX} ${OBJS_PARSING} ${OBJS_UTILS} ${OBJS_INIT} ${OBJS_CLEAN} ${DEPS_FILES}
				@echo "Deleting ${_RED}${_BOLD}libft binary files${_END}..."
				@${MAKE} -C libft clean >/dev/null

fclean:			clean
				@echo "Deleting ${_RED}${_BOLD}pipex and checker${_END}..."
				@${RM} ${OBJS_MAIN} ${OBJS_PIPEX} ${OBJS_PARSING} ${OBJS_UTILS} ${OBJS_INIT} ${OBJS_CLEAN} ${NAME}
				@echo "Deleting ${_RED}${_BOLD}libft librairy${_END}..."
				@${MAKE} -C libft fclean >/dev/null

re:				fclean all

-include ${DEPS_FILES}

.PHONY:			all clean fclean re bonus 
