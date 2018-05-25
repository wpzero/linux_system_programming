CC=gcc
OBJ=signal_sample.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)
signal_sample: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.DEFAULT_GOAL := signal_sample
.PHONY: clean
clean:
	-rm -rf $(OBJ) signal_sample
