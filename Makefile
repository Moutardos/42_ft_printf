CC = cc
AR= ar
LIBFT = libft
NAME = libftprintf.a
SRC = printf.c convert.c
OBJ = $(SRC:.c=.o)
RM = rm -f
LIBFLAGS = -rc
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)


$(NAME) : $(OBJ)
	$(MAKE) -C $(LIBFT)
	cp $(LIBFT)/$(LIBFT).a $(LIBFT).a
	cp $(LIBFT).a $(NAME)
	$(AR) $(LIBFLAGS) $(NAME) $(OBJ) 

%.o : %.c
	$(CC) $(CFLAGS)  -o $@ -c $<

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT) $@
	
fclean : clean
	$(RM) $(NAME)
	$(RM) test
	$(MAKE) -C $(LIBFT) $@
	$(RM) $(LIBFT).a

re: fclean all

.PHONY: all clean fclean re test
