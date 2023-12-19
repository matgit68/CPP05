RED		:= \033[31;1m
YELLOW	:= \033[33;1m
RESET	:= \033[0m

NAME = ex02

CXX = c++
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror -fsanitize=address

SRC =	AForm.cpp\
		Bureaucrat.cpp\
		main.cpp\
		PresidentialPardonForm.cpp\
		RobotomyRequestForm.cpp\
		ShrubberyCreationForm.cpp\

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJ)
	@printf '$(RED)- $(NAME) done -$(RESET)\n'

clean:
	@printf '$(YELLOW)Cleaning $(NAME) $(RESET)\n'
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)
