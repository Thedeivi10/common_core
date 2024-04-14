
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c

SUBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SUBJ)
	ar rc $(NAME) $(SUBJ)

clean: 
		rm -rf $(SUBJ)