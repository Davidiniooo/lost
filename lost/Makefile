CC		:= g++
C_FLAGS := -std=c++17 -Wall -Wextra -g

BIN		:= bin
SRC		:= src/*.cpp src/core/*.cpp src/entities/*.cpp src/gfx/*.cpp src/items/*.cpp src/worlds/*.cpp src/worlds/layers/*.cpp src/input/*.cpp

INCLUDE	:= include -Isrc
LIB		:= lib

LIBRARIES	:= -lsfml-graphics -lsfml-window -lsfml-system

ifeq ($(OS),Windows_NT)
EXECUTABLE	:= main.exe
else
EXECUTABLE	:= main
endif

all: $(BIN)/$(EXECUTABLE)

clean:
	$(RM) $(BIN)/$(EXECUTABLE)

run: all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)
	$(CC) $(C_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)