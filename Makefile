NAME = pipex
OUTFILE = outfile
FLAGS = -Wall -Werror -Wextra -g
CC = gcc

HEADERS_DIR = includes/
HEADERS_FILES = pipex.h
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_FILES))

SRCS_BONUS = bonus/
SRCS_FILES_B = child.c error.c file_manager.c free.c here_doc.c main.c utils.c
SRCS_B = $(addprefix $(SRCS_BONUS), $(SRCS_FILES_B))
OBJS_B = ${SRCS_B:.c=.o}

SRCS_DIR = src/
SRCS_FILES = main.c error.c child.c utils.c free.c here_doc.c file_manager.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS = ${SRCS:.c=.o}

FUNC_DIR = fonctions/
FUNC_FILES = ft_split.c ft_strjoin.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_substr.c get_next_line.c get_next_line_utils.c ft_putstr_fd.c
FUNC = $(addprefix $(FUNC_DIR), $(FUNC_FILES))
OBJS_F = $(FUNC:.c=.o)


#COMMANDES
%.o: %.c
		@${CC} ${FLAGS} -c $< -o $@

$(NAME): $(OBJS_F) $(OBJS)
		@$(CC) $(OBJS_F) $(OBJS) -o $(NAME)

all: $(NAME)

bonus: $(OBJS_F) $(OBJS_B)
		@$(CC) $(OBJS_F) $(OBJS_B) -o $(NAME)

clean:
		@rm -f $(OBJS)
		@rm -f $(OBJS_F)
		@rm -f $(OBJS_B)

fclean: clean
		@rm -f $(NAME)
		@rm -f $(OUTFILE)

re: fclean all

.PHONY: all clean fclean re
