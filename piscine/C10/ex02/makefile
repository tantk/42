TARGET = ft_tail
SRCFILES = main.c utility.c utility2.c utility3.c parse.c display.c
OBJECTS = main.o utility.o utility2.o utility3.o parse.o display.o
CFLAGS = -g -Wall -Wextra -Werror
CC = cc

all : $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

