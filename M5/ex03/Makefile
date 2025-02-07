# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 14:46:35 by shaboom           #+#    #+#              #
#    Updated: 2025/02/07 12:21:17 by araveala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TEST_DIR = tests
SRC_DIR = src
INCS = incs
CPPFILES = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(TEST_DIR)/*.cpp)
HPPFILES = $(wildcard $(INCS)/*.hpp)
CPP = c++
CPPFLAGS = -I$(SRC_DIR) -I$(INCS) -Werror -Wextra -Wall -Wshadow -std=c++11 -MMD -MP
#-Wshadow shows error when variables share a name that have shared scope . -Wno-shadow tunrs off warnings for -Wshadow
BUILDDIR = buildofiles/
OFILES = $(addprefix $(BUILDDIR), $(notdir $(CPPFILES:.cpp=.o)))
DEPFILES = $(OFILES:.o=.d)
EXEC = Bureaucrat


all: $(BUILDDIR) $(EXEC)

$(BUILDDIR)%.o: $(SRC_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -g -c $< -o $@

$(BUILDDIR)%.o: $(TEST_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -g -c $< -o $@

$(EXEC): $(OFILES)
	$(CPP) $(CPPFLAGS) $(OFILES) -o $(EXEC)
	@echo "\033[0;95m Created executable\033[0m"

$(BUILDDIR):
	mkdir -p $(BUILDDIR)
	@echo "\033[0;91m Build folder created\033[0m"

-include $(DEPFILES)

clean:
	rm -rf $(BUILDDIR)
	rm -rf $(OFILES)
	rm -rf $(DEPFILES)
	@echo "\033[0;93m build directory, ofiles and depency files cleaned out\033[0m"

fclean: clean
	rm -f $(EXEC)
	@echo "\033[0;91m executbale removed\033[0m"

re: fclean all $(EXEC)

.PHONY: all clean fclean re