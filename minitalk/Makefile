CLIENT = client
CLIENT_BONUS = client_bonus
SERVER = server
SERVER_BONUS = server_bonus
CFLAGS = -Wall -Wextra -Werror 

all: $(SERVER) $(CLIENT)

$(NAME): all

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(CLIENT_BONUS):
	gcc $(CFLAGS) client_bonus.c -I include $(LIBFT) -o $(CLIENT_BONUS)

$(SERVER_BONUS):
	gcc $(CFLAGS) server_bonus.c -I include $(LIBFT) -o $(SERVER_BONUS)

$(SERVER):
	gcc $(CFLAGS) server.c $ -o $(SERVER)

$(CLIENT):
	gcc $(CFLAGS) client.c $ -o $(CLIENT)

clean:
	rm -rf $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

fclean: clean

re: fclean all bonus

.PHONY: all flean clean re
