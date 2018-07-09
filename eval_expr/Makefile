NAME = eval_expr
FILES = evalexpr ft ft_stack operators operations
SRC_DIR = srcs/
INCLUDES_DIR = ./includes/
FLAGS = -Wall -Wextra -Werror
SRCS = $(patsubst %, %.c, $(FILES))
BINS = $(patsubst %, %.o, $(FILES))

.PHONY: all clean fclean $(NAME) compile

all: $(NAME)

compile:
	@gcc -I$(INCLUDES_DIR) $(FLAGS) -c $(patsubst %, $(SRC_DIR)%, $(SRCS))

$(NAME): compile
	@gcc -I$(INCLUDES_DIR) $(FLAGS) main.c $(BINS) -o $(NAME)	

clean:
	@/bin/rm -f $(BINS) 

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
