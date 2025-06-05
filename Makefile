CC = gcc
CFLAGS = -Wall -MMD -Iinclude
SRC = src/main.c src/inventaris.c
OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)
OUT = main

all: $(OUT)
	$(MAKE) clean_obj
	./$(OUT)

$(OUT): $(OBJ)
	$(CC) -o $@ $^

-include $(DEP)

clean_obj:
	rm -f src/*.o src/*.d

clean:
	rm -f *.o *.d $(OUT)