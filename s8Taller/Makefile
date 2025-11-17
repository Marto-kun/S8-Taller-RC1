TARGET = produccion

CC = gcc

CFLAGS = -Wall -Wextra -std=c11

SRCS = main.c funciones.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c funciones.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)

mrproper: clean
