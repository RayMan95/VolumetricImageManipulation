CC=g++

default:
	$(CC) -c -o driver.o driver.cpp -std=c++11
	$(CC) -c -o VolImage.o VolImage.cpp -std=c++11
	$(CC) -o volImage driver.o VolImage.o -std=c++11

debug:
	$(CC) -g driver.cpp VolImage.cpp -std=c++11
	gdb ./a.out

run: default
	./volImage

clean:
	rm *.o
	rm volImage
	rm a.out
