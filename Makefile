OBJS = main.c
CC = gcc
LINKER_FLAGS = -lSDL2 -lm
COMPILER_FLAGS =

OBJ_NAME = poopboy

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
