NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
XFLAGS = -lbsd -lmlx -lXext -lX11
SRCS_FILES = main quit fractal hooks movement zoom ft_atof newton colors_part1 colors_part2
HEADERS_FILES = fractol buttons ft_printf
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
HEADERS = $(addprefix $(HEADERS_DIR), $(addsuffix .h, $(HEADERS_FILES)))
SRCS_DIR = srcs/
OBJS_DIR = objs/
HEADERS_DIR = headers/
LIB_DIR = libs/

all:
	mkdir -p $(OBJS_DIR)
	make $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(HEADERS) $(OBJS) libs
	$(CC) $(CFLAGS) $(SRCS) libs/libftprintf.a $(XFLAGS) -o $(NAME)

$(HEADERS):
	ln printf/srcs/ft_printf.h $(HEADERS_DIR)

libs: $(HEADERS)
	make -C ./printf
	mkdir -p $(LIB_DIR)
	mv ./printf/libftprintf.a $(LIB_DIR)

clean:
	make clean -C ./printf
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf libs
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
