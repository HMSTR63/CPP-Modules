CPPC = c++ -std=c++98
CPPFLAGS = -Wall -Wextra -Werror
NAME = replace

SRC = main.cpp Sed.cpp 
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

all: $(NAME)

-include $(DEP)

$(NAME): $(OBJ)
	@echo "\033[1;32m✅ Compiling complete source code into executable...\033[0m"
	@$(CPPC) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[1;32m🎉 Build successful! You can now run ./$(NAME)\033[0m"

%.o: %.cpp
	@$(CPPC) $(CPPFLAGS) -MMD -c $< -o $@
	@echo "\033[1;34m🔹 Compiling: $< -> $@\033[0m"

clean:
	@echo "\033[0;33m🧼 Removing compiled object files to clean up...\033[0m"
	@rm -f $(OBJ) $(DEP)
	@echo "\033[0;32m✔️  Clean complete.\033[0m"

fclean: clean
	@echo "\033[0;31m🗑️ Removing final executable ($(NAME))...\033[0m"
	@rm -f $(NAME)
	@echo "\033[0;32m✔️  Full clean complete.\033[0m"

re: fclean all