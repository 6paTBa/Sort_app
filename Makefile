all: bin/sort_app

bin/sort_app: build/main.o build/functions.o build/sort.o
	gcc -Wall -Werror build/main.o build/functions.o build/sort.o -o bin/sort_app

build/functions.o: src/functions.c
	gcc -Wall -Werror -c src/functions.c -o build/functions.o 

build/sort.o: src/sort.c
	gcc -Wall -Werror -c src/sort.c -o build/sort.o 

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o 
clean:
	rm -rf build/*.o bin/sort_app

.PHONY: all clean

