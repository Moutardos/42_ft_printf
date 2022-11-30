CC = cc
AR= ar
LIBFT = libft
NAME = libftprint.a
SRC = printf.c convert.c
OBJ = $(SRC:.c=.o)
RM = rm -f
LIBFLAGS = -rc
CFLAGS = -Wall -Wextra -Werror -o 

all: $(NAME)


$(NAME) : $(OBJ)
	$(MAKE) -C $(LIBFT)
	cp $(LIBFT)/$(LIBFT).a $(LIBFT).a
	$(AR) $(LIBFLAGS) $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) $@ -c $< 

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT) $@
	
fclean : clean
	$(RM) $(NAME)
	$(RM) test
	$(MAKE) -C $(LIBFT) $@

re: fclean all

.PHONY: all clean fclean re test
