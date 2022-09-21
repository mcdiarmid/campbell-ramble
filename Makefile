CC = gcc
CFLAGS = -Wall -Werror -Wmissing-prototypes
GLLIBS = -lGL -lGLEW -lglut

all:
	@echo "Making"
	$(CC) $(CFLAGS) src/main.c -o bin/windowtest.out $(GLLIBS)
