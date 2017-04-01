CC=g++

default:
	$(CC) -c -o driver.o driver.cpp -std=c++11
	$(CC) -c -o VolImage.o VolImage.cpp -std=c++11
	$(CC) -o volimage driver.o VolImage.o -std=c++11

debug:
	$(CC) -g driver.cpp VolImage.cpp -std=c++11
	gdb ./a.out

run:
	./main

clean:
	rm *.o
	rm volimage