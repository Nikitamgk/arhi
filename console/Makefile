APP_NAME = pr02
CC = gcc
CFLAGS = -I ../include -Wall
SRC = c
SC_LIB = libsc.a

SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = bin

APP_PATH = $(BIN_DIR)/$(APP_NAME)
APP_SOURCES = $(wildcard $(SRC_DIR)/*.$(SRC_EXT)) ../mySimpleComputer/bin/$(SC_LIB)
APP_OBJECTS = $(APP_SOURCES:%.$(SRC_EXT)=$(OBJ_DIR)/%.o)
DEPS = $(APP_OBJECTS:.o=.d)

.PHONY: all clean

all: $(BIN_DIR) $(OBJ_DIR) $(LIB_PATH) $(APP_PATH)

-include $(DEPS)

$(BIN_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)
	$(CC) -MMD -c $(CFLAGS) $< -o $@

$(BIN_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)