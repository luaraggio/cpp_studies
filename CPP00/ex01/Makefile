NAME = PhoneBook

CC = c++

C_FLAGS = -Wall -Wextra -Werror -std=c++98 -g

PURPLE= \033[0;35m
BLUE= \033[0;34m
RESET= \033[0m

SRCS =	main.cpp \
		PhoneBook.cpp \
		Contact.cpp \
		InputVerifications.cpp

OBJS = ${SRCS:.cpp=.o}

%.o: %.cpp
	@$(CPP) $(FLAGS) -c $< -o $@

all:	$(NAME)
		@echo "$(PURPLE) 📞 $(NAME) is ready.$(RESET)"

$(NAME):	$(OBJS)
			@$(CC) $(C_FLAGS) $(SRCS) -o $(NAME)

clean:
		@rm -f $(OBJS)
		@echo "$(BLUE) 📤 Objects deleted$(RESET)"

fclean:
		@rm -f $(NAME)
		@rm -f $(OBJS)
		@echo "$(BLUE) 🧼 All cleaned$(RESET)"

re: fclean all

val: re
	valgrind  --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME)
