OBJ = dyn_array.o func.o
DEPS = func.h
TARGET = a.out

CC = gcc
CFLAGS = -g -Wall -O0 -std=c99
LIBS = 

%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET):$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY : clean

clean:
	rm -f *.o *.out

