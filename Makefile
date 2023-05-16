# Colors
BLU = \033[0;34m
GRN = \033[0;32m
YEL = \033[0;33m
RED = \033[0;31m
WHT = \033[0;37m
ORG = \033[38;5;202m
RESET = \033[0m

NAME = coRSAir

CFLAGS = -Wall -Wextra -Werror
RSAFLAGS = -lssl -lcrypto
SANITIZE = -g3 -fsanitize=address
CC = gcc

# Folders
LIBFT_DIR = libft/
INC_DIR = inc/
SRC_DIR = src/
OBJ_DIR = obj/
RSA_INC = -I/Users/tomartin/homebrew/Cellar/openssl@3/3.1.0/include/

# Paths
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

# Libft linkers
LNK = -L$(LIBFT_DIR) -lft
RSA_LNK = -L/Users/tomartin/homebrew/Cellar/openssl@3/3.1.0/lib


# Files
SRC_FILES = corsair.c read_cert.c

SRC = $(addprefix $(SRC_DIR),$(SRC_FILES))

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_FILES))

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -I$(RSA_INC) -o $@ -c $<
	@echo "$(ORG)Compiling $<$(RESET)"

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(RSAFLAGS) $(RSA_LNK) $(SANITIZE)\
		$(LNK) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GRN)$(NAME) has been compiled successfully!$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "$(YEL)Object files have been removed!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(YEL)$(NAME) executable has been removed!$(RESET)"

re: fclean all

print:
	@echo $(LNK)
	@echo $(OBJ)
	@echo $(SRC)
	@echo $(LIBFT)
	@echo $(INC_DIR)
	@echo $(LIBFT_DIR)