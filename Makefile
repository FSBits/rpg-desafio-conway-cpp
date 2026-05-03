CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++17

INCLUDES = -I./include

SRC = $(wildcard src/*.cpp)

OBJ = $(SRC:.cpp=.o)

EXEC = cyberpunk_rpg

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f src/*.o $(EXEC)