#Variables

NAME			= push_swap
BONUS_NAME		= checker
SRC_DIR			= src/
BONUS_SRC_DIR	= bonus/
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
RM				= rm -f

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

SRC_FILES		=	push_swap sorting_calculations sorting stack_check stack_functions stack_read
SRC		 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
BONUS_SRC_FILES	=	checker stack_bonus_functions stack_read_bonus
BONUS_SRC 		= 	$(addprefix $(BONUS_SRC_DIR), $(addsuffix .c, $(BONUS_SRC_FILES)))

INCLUDES=libft/libft.a get_git/get_next_line.a

all:
	@make -C libft/ all
	@make -C get_git/ all
	gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES)
	@echo "$(GREEN)All compiled.$(DEF_COLOR)"

clean:
	@make -C libft/ clean
	@make -C get_git/ clean
	@echo "$(CYAN)Objects cleaned.$(DEF_COLOR)"

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	@make -C libft/ fclean
	@make -C get_git/ fclean
	@echo "$(BLUE)Executable cleaned.$(DEF_COLOR)"

re: fclean all
	@echo "$(RED)Recompiled!$(DEF_COLOR)"

bonus:
	@make -C libft/ all
	@make -C get_git/ all
	gcc $(BONUS_SRC) -o $(BONUS_NAME) $(FLAGS) $(INCLUDES)
	@echo "$(YELLOW)Bonus checker compiled.$(DEF_COLOR)"

.PHONY: all clean fclean re bonus