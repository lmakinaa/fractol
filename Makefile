HELPERS_DIR=./helpers
INCLUDES=./includes
HEADER=./includes/helpers.h
CFLAGS = -Wall -Wextra -Werror
CC=cc
NAME=fractol
MAIN=main.o
HELPERS_O=$(HELPERS_DIR)/colors.o $(HELPERS_DIR)/events.o $(HELPERS_DIR)/pixels.o $(HELPERS_DIR)/ft_numbase_len.o $(HELPERS_DIR)/ft_printf.o $(HELPERS_DIR)/ft_putaddr.o $(HELPERS_DIR)/ft_puthex.o $(HELPERS_DIR)/ft_putchar.o\
	$(HELPERS_DIR)/ft_putnbr.o $(HELPERS_DIR)/ft_putstr.o $(HELPERS_DIR)/ft_atoi.o $(HELPERS_DIR)/comp_square.o $(HELPERS_DIR)/ft_strncmp.o $(HELPERS_DIR)/program_init.o  $(HELPERS_DIR)/scaling_down.o $(HELPERS_DIR)/following_the_mouse.o\
	$(HELPERS_DIR)/events_data_inits.o $(HELPERS_DIR)/program_rendering.o $(HELPERS_DIR)/mandelbrot.o $(HELPERS_DIR)/julia.o $(HELPERS_DIR)/ft_strcmp.o $(HELPERS_DIR)/ft_isdigit.o $(HELPERS_DIR)/ft_atodbl.o $(HELPERS_DIR)/burning_ship.o

all: $(NAME)

$(NAME): $(HELPERS_O) $(MAIN)
	$(CC) $(CFLAGS) $^ -lmlx -framework OpenGL -framework AppKit -o $@

$(HELPERS_DIR)/%.o: $(HELPERS_DIR)/%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

main.o: main.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f main.o $(HELPERS_O)

fclean: clean
	@rm -f fractol

re: clean all

.PHONY: clean