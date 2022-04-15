

SRC = main.cpp
LIBS = -lsfml-window -lsfml-graphics -lsfml-system -lm
CC = g++

OUT = pi

all:
	$(CC) $(SRC) $(LIBS) -o $(OUT)
	
