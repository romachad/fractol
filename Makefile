NAME = fractol
NAME_B = fractol_b
CC = cc
CFLAGS = -Wall -Wextra -Werror
XFLAGS = -lbsd -lmlx -lXext -lX11
COMMON_FILES = quit zoom ft_atof colors_part1 colors_part2
SRCS_FILES = main fractal hooks movement
BONUS_FILES = main_bonus fractal_bonus hooks_bonus movement_bonus newton_bonus
HEADERS_FILES = fractol buttons ft_printf
COMMON = $(addprefix $(C_DIR), $(addsuffix .c, $(COMMON_FILES)))
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
OBJS_C = $(addprefix $(OBJS_C_DIR), $(addsuffix .o, $(COMMON_FILES)))
OBJS_B = $(addprefix $(OBJS_B_DIR), $(addsuffix .o, $(BONUS_FILES)))
HEADERS = $(addprefix $(HEADERS_DIR), $(addsuffix .h, $(HEADERS_FILES)))
BONUS = $(addprefix $(BONUS_DIR), $(addsuffix .c, $(BONUS_FILES)))
SRCS_DIR = srcs/
C_DIR = common_srcs/
OBJS_DIR = objs/
OBJS_C_DIR = objs_common/
OBJS_B_DIR = objs_bonus/
HEADERS_DIR = headers/
LIB_DIR = libs/
BONUS_DIR = bonus/

all:
	make $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_C_DIR)%.o: $(C_DIR)%.c
	@mkdir -p $(OBJS_C_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_B_DIR)%.o: $(BONUS_DIR)%.c
	@mkdir -p $(OBJS_B_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(HEADERS) $(OBJS) $(OBJS_C) libs
	$(CC) $(CFLAGS) $(COMMON) $(SRCS) libs/libftprintf.a $(XFLAGS) -o $(NAME)

bonus: $(HEADERS) $(OBJS_B) $(OBJS_C) libs
	make $(NAME_B)

$(NAME_B): $(HEADERS) $(OBJS_B) $(OBJS_C) libs
	$(CC) $(CFLAGS) $(COMMON) $(BONUS) libs/libftprintf.a $(XFLAGS) -o $(NAME_B)

$(HEADERS):
	ln printf/srcs/ft_printf.h $(HEADERS_DIR)

libs: $(HEADERS)
	make -C ./printf
	mkdir -p $(LIB_DIR)
	mv ./printf/libftprintf.a $(LIB_DIR)

clean:
	make clean -C ./printf
	rm -rf $(OBJS_DIR)
	rm -rf $(OBJS_C_DIR)
	rm -rf $(OBJS_B_DIR)

fclean: clean
	rm -rf libs
	rm -rf $(HEADERS_DIR)ft_printf.h
	rm -rf $(NAME)
	rm -rf $(NAME_B)

re: fclean all

.PHONY: all clean fclean re
