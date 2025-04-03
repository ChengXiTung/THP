# THP/Makefile

# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -pedantic -std=c++17 -Iinclude
LDFLAGS := 

# Source and object files
SRC_DIR := src
OBJ_DIR := obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
DEPS := $(OBJ_FILES:.o=.d)

# Executable name
EXEC := poker_game

# Default target
all: $(EXEC)

# Link object files to create executable
$(EXEC): $(OBJ_FILES)
	$(CXX) $(LDFLAGS) $^ -o $@

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# Create obj directory if not exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Include auto-generated dependencies
-include $(DEPS)

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

.PHONY: all clean