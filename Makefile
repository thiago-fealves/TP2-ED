CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude -g

SRC = src
OBJ = obj
BIN = bin
TARGET = $(BIN)/tp2.out 

SRC_FILES = $(wildcard $(SRC)/*.cpp)
OBJ_FILES = $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SRC_FILES))

.PHONY: all clean

all: $(BIN) $(OBJ) $(TARGET)

$(BIN):
	mkdir -p $@

$(OBJ):
	mkdir -p $@

$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ)/%.o: $(SRC)/%.cpp | $(OBJ)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(BIN)
