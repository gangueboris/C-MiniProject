main.exe: init.o main.o
	gcc init.o main.o -o init.exe -lm
init.o: init.c header.h
	gcc -c init.c -o init.o
main.o: main.c header.h
	gcc -c main.c -o main.o
clean:
	rm *.o init.exe