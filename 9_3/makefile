CC=gcc
OBJ=signal_kill.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)
signal_kill: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.DEFAULT_GOAL := signal_kill
.PHONY: clean
clean:
	-rm -rf $(OBJ) signal_kill
