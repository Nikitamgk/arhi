APP_NAME = pr02
CC = gcc
CFLAGS = -I ../include -Wall
SRC = c
SC_LIB = libsc

SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = bin

APP_PATH = $(BIN_DIR)/$(APP_NAME)
APP_SOURCES = $(wildcard $(SRC_DIR)/*.$(SRC_EXT)) 
SC_OBJ = $(wildcard ../mySimpleComputer/obj/*.o)
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
	$(CC) -MMD -c $(CFLAGS) $< -o $@

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) test.c $^ -o $@ $(SC_LIB).a $(SC_OBJ) $(APP_OBJECTS)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)