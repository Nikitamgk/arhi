APP_NAME = pr02
CC = gcc
CFLAGS = -Wall -I ../include
SRC = c
SC_LIB = libsc

SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = bin

APP_PATH = $(BIN_DIR)/$(APP_NAME)
APP_SOURCES = $(wildcard print*.c) 
SC_LIB_SRC = ../mySimpleComputer/bin
APP_OBJECTS = $(patsubst %.c, %.o, $(APP_SOURCES))
DEPS = $(APP_OBJECTS:.o=.d)

.PHONY: all clean

all: $(BIN_DIR) $(OBJ_DIR) $(LIB_PATH) $(APP_PATH)

-include $(DEPS)

$(BIN_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)
	$(CC) -MMD -fPIC -c $< $(CFLAGS) -o $@

$(APP_PATH) : $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) -fPIC test.c $(SC_LIB_SRC)/$(SC_LIB).a -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(APP_OBJECTS) console.a