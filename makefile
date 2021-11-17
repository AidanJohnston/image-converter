# Complier
CC := g++

# Define Directories
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

# Name executable
EXE := $(BIN_DIR)/main

# Collect all src files
SRC := $(wildcard $(SRC_DIR)/*.cpp)

# List object files
OBJ := $(SRC:$(SRC_DIR)/%.c = $(OBJ_DIR)/%.o)

# Complier Flags
CXXFLAGS = -Iinclude -MMD -MP
CFLAGS = -Wall
LDLIBS = -lm
LDFLAGS  := -Llib

.PHONY: all clean

all: $(EXE)

# Create Object Files
$(EXE): $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

# Create executable from object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CXXFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@rm -rfv $(BIN_DIR) $(OBJ_DIR)

run: 
	./bin/main $(arg)