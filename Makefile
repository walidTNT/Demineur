CC = gcc
NAME = demineur4
SRC = $(wildcard ./etape_4/*.c) $(wildcard ./etape_3/sources/*.c) $(wildcard ./etape_3/libmy/*.c)
CFLAGS = -Wall -Wextra -Werror -pedantic
LDFLAGS	= -L.	-lpthread
OBJ = $(SRC:%.c=%.o)
CLEAN   = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
