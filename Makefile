NAME = pipex

CC = cc -Wall -Wextra -Werror
CFLAGS = -g
RM = rm -f




SRC_FOLDER = src/
UTILS_FOLDER = utils/
LIBSFUNCS_FOLDER = libs/

SRCS = $(addprefix $(SRC_FOLDER), \
	main.c )

UTILS = $(addprefix $(UTILS_FOLDER), \
	err.c \
	child.c \
	files.c \
	path.c \
	store.c \
	cmd.c \
	free_func.c)
LIBSFUNCS = $(addprefix $(LIBSFUNCS_FOLDER), \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putstr_fd.c  \
	ft_split.c   \
	ft_strncmp.c \
	ft_strlen.c)

ALL_SRCS = $(SRCS) $(UTILS) $(LIBSFUNCS)

OBJS = $(ALL_SRCS:.c=.o)


all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all