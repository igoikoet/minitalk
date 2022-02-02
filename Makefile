CC = gcc

CFLAGS = -Werror -Wall -Wextra #-g -fsanitize=address

SERVER = server
SERVER_SRCS = server.c
SERVER_BONUS = server_bonus
SERVER_BONUS_SRCS = server_bonus.c

CLIENT = client
CLIENT_SRCS = client.c
CLIENT_BONUS = client_bonus
CLIENT_BONUS_SRCS = client_bonus.c

LIBFT = ./libft/libft.a

RM = rm -rf

all : $(SERVER) $(CLIENT) $(LIBFT) $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT) : $(LIBFT) $(CLIENT_SRCS)
	$(CC) $(CFLAGS) $(CLIENT_SRCS) $(LIBFT) -o $(CLIENT)

$(SERVER) : $(LIBFT) $(SERVER_SRCS)
	$(CC) $(CFLAGS) $(SERVER_SRCS) $(LIBFT) -o $(SERVER)

$(LIBFT): libft/*.c libft/*.h
		$(MAKE) -C libft/

bonus : $(LIBFT) $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS) : $(LIBFT) $(SERVER_BONUS_SRCS)
	$(CC) $(CFLAGS) $(SERVER_BONUS_SRCS) $(LIBFT) -o $(SERVER_BONUS)

$(CLIENT_BONUS) : $(LIBFT) $(CLIENT_BONUS_SRCS)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_SRCS) $(LIBFT) -o $(CLIENT_BONUS)

clean :
		$(MAKE) -C libft/ clean
	
fclean: clean
		$(RM) $(CLIENT) $(SERVER) $(LIBFT) $(SERVER_BONUS) $(CLIENT_BONUS)

re : fclean all

.PHONY: all clean fclean re bonus
