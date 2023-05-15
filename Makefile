CC = gcc
FLAGS = -Wall -Werror -Wextra
NAMEC =	client
NAME =	server
NAMEBC =	bclient
NAMEBS =	bserver
SOURCEC =	client.c\
			ft_atoi.c\


SOURCES =	server.c\
			ft_putnbr.c\
			ft_putchar.c\

BONUSC =	client_bonus.c\
			ft_atoi.c\

BONUSS =	server_bonus.c\
			ft_putnbr.c\
			ft_putchar.c\

OBJC = $(SOURCEC:.c=.o)
OBJS = $(SOURCES:.c=.o)

OBJBC = $(BONUSC:.c=.o)
OBJBS = $(BONUSS:.c=.o)

purple = \033[0;35m
red = \e[0;31m
yellow = \e[0;33m

define mini
$(purple)
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█░▄▀▄░██▄██░▄▄▀██▄██▄░▄█░▄▄▀█░██░█▀
█░█▄█░██░▄█░██░██░▄██░██░▀▀░█░██░▄▀
█▄███▄█▄▄▄█▄██▄█▄▄▄██▄██▄██▄█▄▄█▄█▄
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀


endef
export mini

define bonuss
$(purple)
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
██░▄▄▀██░▄▄▄░██░▀██░██░██░██░▄▄▄░
██░▄▄▀██░███░██░█░█░██░██░██▄▄▄▀▀
██░▀▀░██░▀▀▀░██░██▄░██▄▀▀▄██░▀▀▀░
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀

endef
export bonuss


all :	$(NAME) $(NAMEC)
		@echo "$$mini"

$(NAME): $(OBJS)
		@$(CC) $(OBJS) $(FLAGS)  -o $(NAME)
		@echo "$(purple) mandatory server setup"

$(NAMEC): $(OBJC)
		@$(CC) $(OBJC) $(FLAGS)  -o $(NAMEC)
		@echo "$(purple) mandatory client done"

clean :
		@rm -rf $(OBJS) $(OBJC) $(OBJBC) $(OBJBS)

fclean :
		@rm -rf $(OBJS) $(OBJC) $(OBJBC) $(OBJBS) $(NAMEBC) $(NAMEBS) $(NAMEC) $(NAME)

re : fclean all

bobo :	$(NAMEBS) $(NAMEBC)
		@echo "$$bonuss"

$(NAMEBS): $(OBJBS)
		@$(CC) $(OBJBS) $(FLAGS)  -o $(NAME)
		@echo "$(purple) bonus server setup"

$(NAMEBC): $(OBJBC)
		@$(CC) $(OBJBC) $(FLAGS)  -o $(NAMEC)
		@echo "$(purple) bonus client done"

bonus : fclean bobo
