# Colors

BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_YELLOW	=	\033[1;33m
NO_COLOR	=	\033[0m
DEF_COLOR 	= \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

SERVER = server
CLIENT = client

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SRCS 		= src/
CLIENT_SRCS = ${SRCS}client.c
SERVER_SRCS = ${SRCS}server.c

CLIENT_SRCS_BONUS = ${SRCS}client_bonus.c
SERVER_SRCS_BONUS = ${SRCS}server_bonus.c

CLIENT_OBJS = ${SRCS}client.o
SERVER_OBJS = ${SRCS}server.o

CLIENT_OBJS_BONUS = ${SRCS}client_bonus.o
SERVER_OBJS_BONUS = ${SRCS}server_bonus.o

CC = gcc
RM = /bin/rm -f
CFLAGS = -Wall -Wextra -Werror
CFLAGS_D = -Wall -Wextra -Werror -g 

MYLIB_DIR	= 	printf
MYLIB		=	$(MYLIB_DIR)/libftprintf.a

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"
SERV_READY	=	echo "📥 Server ready!\n"
CLI_READY	=	echo "📟 Client ready!\n"
CLEANED		=	echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"
FCLEANED	=	echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

###

all: 
	@Make libs
	@echo "\n🚧 $(YELLOW)Compiling Server..$(NO_COLOR)"	
	@Make -s $(SERVER)
	@$(SERV_READY)	
	@echo "\n🚧 $(YELLOW)Compiling Client..$(NO_COLOR)"	
	@Make -s $(CLIENT)
	@$(CLI_READY)

bonus: 
	@Make libs
	@echo "\n🚧 $(YELLOW)Compiling Server..$(NO_COLOR)"	
	@Make -s $(SERVER_BONUS)
	@$(SERV_READY)	
	@echo "\n🚧 $(YELLOW)Compiling Client..$(NO_COLOR)"	
	@Make -s $(CLIENT_BONUS)
	@$(CLI_READY)

libs:
	@echo "\n$(GRAY)➖➖➖➖➖    LIBS    ➖➖➖➖➖➖$(NO_COLOR)\n"
	@$(MAKE) -C $(MYLIB_DIR)
	@echo "\n$(GRAY)➖➖➖➖➖ LIBS  DONE ➖➖➖➖➖➖➖➖➖$(NO_COLOR)\n"	

$(SERVER): $(SERVER_OBJS) $(MYLIB) Makefile
	@echo "🍕 $(WHITE)$(CC) $(CFLAGS) $(SERVER_OBJS) $(MYLIB) -o $(SERVER)$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(SERVER_OBJS) $(MYLIB) -o $(SERVER)

$(SERVER_BONUS): $(SERVER_OBJS_BONUS) $(MYLIB) Makefile
	@echo "🍕 $(WHITE)$(CC) $(CFLAGS) $(SERVER_OBJS_BONUS) $(MYLIB) -o $(SERVER_BONUS)$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(SERVER_OBJS_BONUS) $(MYLIB) -o $(SERVER_BONUS)

$(CLIENT): $(CLIENT_OBJS) $(MYLIB) Makefile
	@echo "🍕 $(WHITE)$(CC) $(CFLAGS) $(CLIENT_OBJS) $(MYLIB) -o $(CLIENT)$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) $(MYLIB) -o $(CLIENT)

$(CLIENT_BONUS): $(CLIENT_OBJS_BONUS) $(MYLIB) Makefile
	@echo "🍕 $(WHITE)$(CC) $(CFLAGS) $(CLIENT_OBJS) $(MYLIB) -o $(CLIENT_BONUS)$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(CLIENT_OBJS_BONUS) $(MYLIB) -o $(CLIENT_BONUS)

$(SRCS)%.o:$(SRCS)%.c
	@${CC} ${CFLAGS} -c $< -o $@
	@echo "🔧 $(GRAY)${CC} ${CFLAGS} -I./ -c $< -o $@$(DEF_COLOR)"

clean:
	@$(MAKE) clean -C $(MYLIB_DIR)
	@$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_OBJS_BONUS) $(CLIENT_OBJS_BONUS)
	@echo "$(MAGENTA)🚽 Cleaned $(SERVER) & $(CLIENT)$(DEF_COLOR)"

fclean: clean
	@$(MAKE) fclean -C $(MYLIB_DIR)
	@$(RM) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	@echo "$(MAGENTA)🚽 Fcleaned $(SERVER) & $(CLIENT)$(DEF_COLOR)"	

re: fclean all

.PHONY: all clean fclean re bonus