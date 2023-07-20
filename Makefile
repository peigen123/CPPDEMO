SRC_DIR := src
INC_DIR := inc
OBJ_DIR := obj
BIN_DIR := bin
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
INCS := $(patsubst $(INC_DIR)/%.h,-I./$(INC_DIR)/%.h,$(wildcard $(INC_DIR)/*.h))
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
TARGET := $(BIN_DIR)/test
INC_DIR_WITH_FLAG := $(foreach dir,$(INC_DIR),-I$(dir))

CC := g++
CFLAGS := -Wall -Wextra -Wpedantic -O0 -g $(INC_DIR_WITH_FLAG)

.PHONY: all clean

all: $(TARGET)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
