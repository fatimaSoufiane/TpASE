CC=gcc
CFLAGS=-m32 
LDFLAGS=
EXEC= pingpong


all: $(EXEC)

pingpong: pingpong.c
	$(CC) -o pingpong init_ctx.c pingpong.c $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
			
