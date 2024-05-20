APP_NAME = pr03
LIB_NAME_SC = libsc
LIB_NAME_MT = libmt
CFLAGS = -Wall
CC = gcc
SRC_EXT = c

SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = bin

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = ../mySimpleComputer/bin/$(LIB_NAME_SC).a ../myTerm/bin/$(LIB_NAME_MT).a
APP_SOURCES = $(wildcard $(SRC_DIR)/*.$(SRC_EXT))
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/%.o)
DEPS = $(APP_OBJECTS:.o=.d)

.PHONY: all clean

all: $(BIN_DIR) $(OBJ_DIR) $(LIB_PATH) $(APP_PATH)

-include $(DEPS)

$(BIN_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $^ -o $@ 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)
	$(CC) -MMD -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)