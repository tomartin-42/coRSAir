# Collors
BLU = \033[0;34m
GRN = \033[0;32m
YEL = \033[0;33m
RED = \033[0;31m
WHT = \033[0;37m
ORG = \033[38;5;202m
RESET = \033[0m        

NAME 			= coRSAir

FLAGS 		= -Wall -Wextra -Werror
SANITIZE	= -g3 -fsanitize=address	
COMPILER  = gcc

# Folders
LIBFT_DIR = ./libft/
OBJ_DIR = obj/

# Files
SRC = main.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c | obj
	@$(COMPILER) $(FLAGS) $(SANITIZE) -c $< -o $@

$(NAME): $(OBJ)
	@$(CXX) $(FLAGS) $(SANITIZE) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
