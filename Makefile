all: clean test

screen.o:
	gcc -c ./src/app/screen.c -o ./build/obj/screen.o

test: screen.o
	./build/bin/screen.o

clean:
	rm -rf ./build/bin/*.exe
	rm -rf ./build/obj/*.o