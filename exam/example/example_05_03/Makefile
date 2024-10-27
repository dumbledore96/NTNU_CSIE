all: mymax.o main.c
	gcc main.c mymax.o -o main
	#gcc main.c -o main -L. -lmymax

mymax: mymax.c
	gcc -c mymax.c -o mymax.o
	gcc -shared mymax.o -o libmymax.so
	
clean:
	rm -f main *.o