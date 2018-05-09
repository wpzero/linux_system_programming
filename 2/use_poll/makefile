CC=gcc
OBJ=main.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)
test_poll: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.DEFAULT_GOAL := test_poll
.PHONY: clean

clean:
	-rm -rf $(OBJ) test_poll
