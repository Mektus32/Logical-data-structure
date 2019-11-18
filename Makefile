.PHONY: all, clean, fclean, re, obj

NAME = lds

# src / obj files
SRC =   WordsList.c \
        Stack.c \
        Text.c \
		main.c

OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

# compiler
CC = gcc
# CFLAGS = -Wextra -Wall -Werror -g

# directories
SRCDIR = ./source/
INCDIR = -I ./includes/
OBJDIR = ./objects/

all: $(NAME)

$(NAME): obj $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(INCDIR) -o $@ -c $<

clean:
	/bin/rm -rf $(OBJDIR)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all