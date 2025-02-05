# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 14:46:35 by shaboom           #+#    #+#              #
#    Updated: 2025/01/17 16:59:05 by shaboom          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = c++
CPPFLAGS = -Werror -Wextra -Wall -Wshadow -Wno-shadow -std=c++11 -MMD -MP
CPPFILES = main.cpp Bureaucrat.cpp AForm.cpp bureaucrat_tests.cpp AForm_tests.cpp

BUILDDIR = buildofiles/
OFILES = $(addprefix $(BUILDDIR), $(CPPFILES:.cpp=.o))
EXEC = Bureaucrat

DEPFILES = $(OFILES:.o=.d)

all: $(BUILDDIR) $(EXEC)

$(BUILDDIR)%.o: %.cpp
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