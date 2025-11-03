# Compile Flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude -g

# Directories
SRC= src
OBJ = obj
BIN = bin
TARGET = $(BIN)/tp.out 

# Files
SRC_FILES = $(wildcard $(SRC)/*.cpp)
OBJ_FILES = $(patsubst $(OBJ)/%.cpp,$(OBJ)/%.o,$(SRC_FILES))

# Phony Targets
.PHONY: all clean

# Target path
all: $(BIN) $(OBJ) $(TARGET)

# Creating dirs if necessary
$(BIN):
	mkdir -p $@

$(OBJ):
	mkdir -p $@

# Compiling
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ)/%.o: $(SRC)/%.cpp | $(OBJ)
	$(CXX) $(CXXFLAGS) -c $< -o $@

#Cleaning
clean:
	rm -rf $(OBJ)/*.o $(TARGET)

