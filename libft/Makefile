NAME		= libft.a
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= gcc
CCFLAGS		= -Wall -Werror -Wextra -I
SRC_FILES	= atoi calloc split strjoin

SRCS 		=	$(addprefix ft_, $(addsuffix .c, $(SRC_FILES)))
OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
