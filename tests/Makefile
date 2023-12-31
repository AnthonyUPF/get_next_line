# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 19:25:20 by anthtorr          #+#    #+#              #
#    Updated: 2023/12/30 16:11:51 by anthtorr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for test_get_next_line

# Compiler
CC = cc

# Common compiler flags
CFLAGS_COMMON = -g -Wall -Wextra -Werror

# File containing the previous BUFFER_SIZE
SIZE_FILE = size.txt

# Read previous BUFFER_SIZE value
PREVIOUS_SIZE = $(shell cat $(SIZE_FILE))

# Set compiler flags based on BUFFER_SIZE, default to CFLAGS_COMMON
ifeq ($(SIZE),)
        CFLAGS = $(CFLAGS_COMMON)
else
        CFLAGS = $(CFLAGS_COMMON) -D BUFFER_SIZE=$(SIZE)
endif

# Include directories
INCLUDES = -I../

# Source files for the default target
SRCS = test_get_next_line.c \
           ../get_next_line.c \
           ../get_next_line_utils.c

# Source files for the bonus target
BONUS_SRCS = test_get_next_line_bonus.c \
           ../get_next_line_bonus.c \
           ../get_next_line_utils_bonus.c

# Object files for the default target
OBJS = $(SRCS:.c=.o)

# Object files for the bonus target
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Target executables
NAME = test_get_next_line
BONUS_NAME = test_get_next_line_bonus

# Default target
all: $(NAME)

# Bonus target
bonus: $(BONUS_NAME)

# Check if BUFFER_SIZE has changed, if so, rebuild
ifeq ($(SIZE),$(PREVIOUS_SIZE))
else
        @echo "Size changed"
        @echo $(SIZE) > $(SIZE_FILE)
        @make re
endif

# Link object files to create executable
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

# Link bonus object files to create bonus executable
$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(BONUS_OBJS) -o $@

# Compile each source file to create object files for the default target
%.o: %.c $(SIZE_FILE) Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile each source file to create object files for the bonus target
bonus_%.o: %.c $(SIZE_FILE) Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Remove object files and target executables for the default target
clean:
	rm -f *.o
	rm -f ../*.o
	rm -f *.gch
	rm -f $(NAME)

# Remove object files, dependencies, and target executables for the bonus target
fclean: clean
	rm -f $(BONUS_NAME)

# Rebuild from scratch for the default target
re: fclean all

# Rebuild from scratch for the bonus target
re_bonus: fclean bonus

# Run norminette on source files
norma: $(SRCS) $(BONUS_SRCS)
	norminette $(SRCS) $(BONUS_SRCS)

# Declare .PHONY targets to avoid conflicts with files
.PHONY: all bonus clean fclean re re_bonus norma

