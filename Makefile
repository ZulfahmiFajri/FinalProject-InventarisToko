CC = gcc
CFLAGS = -Wall -MMD
SRC = menu.c inventaris.c
OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)
OUT = menu

all: $(OUT)
	$(MAKE) clean_obj
	./$(OUT)

$(OUT): $(OBJ)
	$(CC) -o $@ $^

-include $(DEP)

clean_obj:
	rm -f *.o *.d

clean:
	rm -f *.o *.d $(OUT)
