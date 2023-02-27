NAME = libft.a

CC= gcc

CCFLAGS= -Wall -Werror -Wextra

SRCS= ft_atoi.c ft_round.c ft_split.c \
	ft_strdup.c ft_strlen.c ft_substr.c \
	ft_wordcount.c hypotenuse.c

OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
