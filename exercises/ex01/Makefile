NAME = phonebook

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = 

OBJS = ${SRCS:.cpp=.o}

%.o: %.cpp
	@$(CPP) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME):	$(OBJS)
			@$(CPP) $(FLAGS) $(SRCS) -o $(NAME)

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
