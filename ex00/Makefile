NAME = a.out
SOURCES = main.cpp Fixed.cpp
INCLUDES = Fixed.hpp

OBJS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.cpp=.o))
SRCS = $(addprefix $(SRC_DIR)/, $(SOURCES))
INCS = $(addprefix $(INC_DIR)/, $(INCLUDES))

SRC_DIR = .
OBJ_DIR = objs
INC_DIR = .

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -I $(INC_DIR)

all : $(NAME)

fclean : 
	rm -rf $(OBJ_DIR)
	rm -rf $(NAME)

re :
	make fclean
	make all

$(NAME) : $(OBJS) $(INCS)
	$(CC) $(CFLAGS) $(OBJS) -I $(INC_DIR) -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) : 
	mkdir $@
