src = $(wildcard *.c)
obj = $(src:.c=.o)

all: $(obj)
	gcc -o main $^

%.o: %.c
	gcc -o $@ -c $<

clean:
	rm -f *.o main	