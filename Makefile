CC=g++
ODIR=obj

output: Main.o GameOfLife.o
	$(CC) Main.o GameOfLife.o -o GameOfLife

GameOfLife.o: GameOfLife.cpp GameOfLife.h
	$(CC) -c GameOfLife.cpp

Main.o: Main.cpp
	$(CC) -c Main.cpp

.PHONY: clean

clean:
	del /q *.o *.exe