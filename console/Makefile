APP_NAME = pr02
LIB_NAME = libsc
CFLAGS = -Wall -I ../include
CC = gcc
SRC_EXT = c

SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = bin

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = ../mySimpleComputer/bin/$(LIB_NAME).a
APP_SOURCES = $(wildcard $(SRC_DIR)/*.$(SRC_EXT))
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/%.o)
DEPS = $(APP_OBJECTS:.o=.d)

.PHONY: all clean

all: $(BIN_DIR) $(OBJ_DIR) $(APP_PATH)

-include $(DEPS)

$(BIN_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

$(APP_PATH):
	$(CC) $(CFLAGS) $(LIB_PATH) test.c -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
