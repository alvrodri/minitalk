SERVER = server
CLIENT = client

SERVER_SRCS = ./srcs/server/server.c ./srcs/util/util.c
CLIENT_SRCS = ./srcs/client/client.c ./srcs/util/util.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT)

clean:
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all
