SRCS_FILES =	char/ft_isdigit.c			\
				char/ft_isprint.c			\
				char/ft_isalnum.c			\
				char/ft_isalpha.c			\
				char/ft_isascii.c			\
				char/ft_toupper.c			\
				char/ft_tolower.c			\
				string/ft_substr.c			\
				string/ft_bzero.c			\
				string/ft_strncmp.c			\
				string/ft_strcmp.c			\
				string/ft_strchr.c			\
				string/ft_strlcpy.c			\
				string/ft_strlcat.c			\
				string/ft_strrchr.c			\
				string/ft_strdup.c			\
				string/ft_strtrim.c			\
				string/ft_strlen.c			\
				string/ft_strmapi.c			\
				string/ft_strnstr.c			\
				string/ft_split.c			\
				string/ft_striteri.c		\
				string/ft_strjoin.c			\
				stdlib/ft_atoi.c			\
				stdlib/ft_itoa.c			\
				lists/ft_lstiter.c			\
				lists/ft_lstsize.c			\
				lists/ft_lstadd_front.c	\
				lists/ft_lstadd_back.c		\
				lists/ft_lstnew.c			\
				lists/ft_lstlast.c			\
				lists/ft_lstdelone.c		\
				lists/ft_lstclear.c			\
				lists/ft_lstmap.c			\
				memory/ft_memcmp.c			\
				memory/ft_memset.c			\
				memory/ft_memcpy.c			\
				memory/ft_memchr.c			\
				memory/ft_memmove.c			\
				memory/ft_calloc.c			\
				fd/ft_putchar_fd.c			\
				fd/ft_putnbr_fd.c			\
				fd/ft_putendl_fd.c			\
				fd/ft_putstr_fd.c			\
				fd/gnl.c

OBJS_FILES 		=		${SRCS:.c=.o}

HEADER_INC		=	-I $(HEADER_PATH)

HEADER_PATH		= 	includes

HEADER_FILES	=	libft.h

SRCS_PATH 		=		.


CC				=	gcc

FLAGS			=	-Wall -Wextra -Werror

RM				=	rm -rf

NAME			=	libft.a

HEADER			=	$(addprefix $(HEADER_PATH)/, $(HEADER_FILES))

SRCS			=	$(addprefix $(SRCS_PATH)/, $(SRCS_FILES))


all		:	$(NAME)


%.o		:	%.c
			$(CC) $(FLAGS) -o $@ -c $< $(HEADER_INC)


$(NAME)		:	$(OBJS_FILES)
			ar rc $(NAME) $(OBJS_FILES)

clean:
			${RM} ${OBJS_FILES} ${OBJ_BONUS}

fclean:		clean
			${RM} ${NAME}

re :		fclean all

.PHONY:		all clean fclean re
