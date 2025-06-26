
all:main.exe

main.exe: main.o cJSON.o
	gcc -o main.exe main.o cJSON.o -lcurl

main.o: main.c cJSON.h
	gcc -c -o main.o main.c

cJSON.o: cJSON.c cJSON.h
	gcc -c -o cJSON.o cJSON.c


clean:
	del *.o
	del main.exe
