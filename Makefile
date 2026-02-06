NAME = satelliteTelemetry
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra
SRC = src/main.cpp src/TelemetryPacket.cpp
INCLUDE = include
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean
