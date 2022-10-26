NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
XFLAGS = -lbsd -lmlx -lXext -lX11
SRCS_FILES = main error fractal hooks movement zoom
HEADERS_FILES = fractol buttons
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
HEADERS = $(addprefix $(HEADERS_DIR), $(addsuffix .h, $(HEADERS_FILES)))
SRCS_DIR = srcs/
OBJS_DIR = objs/
HEADERS_DIR = headers/

all:
	mkdir -p $(OBJS_DIR)
	make $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) $(XFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
