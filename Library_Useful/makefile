main.exe: hashMap.o main.o
	gcc hashMap.o main.o -o hashMap.exe -lm
hashMap.o: hashMap.c hashMap.h
	gcc -c hashMap.c -o hashMap.o -lm
main.o: main.c hashMap.h
	gcc -c main.c -o main.o
clean:
	rm *.o hashMap.exe