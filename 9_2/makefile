CC=gcc
OBJ=signal_str.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)
signal_str: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.DEFAULT_GOAL := signal_str
.PHONY: clean
clean:
	-rm -rf $(OBJ) signal_str
