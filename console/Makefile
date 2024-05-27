APP_NAME = pr03
LIB_SC = libsc
LIB_MT = libmt
LIB_BC = libbc
CFLAGS = -Wall -I ../include
CC = gcc
SRC_EXT = c

SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = bin

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = ../mySimpleComputer/bin/$(LIB_SC).a  ../myTerm/bin/$(LIB_MT).a ../myTerm/bin/$(LIB_BC).a
APP_SOURCES = $(wildcard $(SRC_DIR)/*.$(SRC_EXT))
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/%.o)
DEPS = $(APP_OBJECTS:.o=.d)

.PHONY: all clean

all: $(BIN_DIR) $(OBJ_DIR) $(APP_OBJECTS) $(APP_PATH)

-include $(DEPS)

$(BIN_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

$(APP_OBJECTS) : $(APP_SOURCES) 
	$(CC) -c $(CFLAGS) $< -o $@

$(APP_PATH): $(LIB_PATH) $(APP_OBJECTS)
	$(CC) $(CFLAGS) $(LIB_PATH) -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

