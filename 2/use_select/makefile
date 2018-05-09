CC=gcc
OBJ=main.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)
test_select: $(OBJ)
	$(CC) -o $@ $< $(CFLAGS)

.DEFAULT_GOAL := test_select
.PHONY: clean

clean:
	-rm -rf $(OBJ) test_select
