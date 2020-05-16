all: bin/sort_app

test: bin/test_app
	./bin/test_app

bin/test_app: build/functions.o build/sort.o build/main_test.o build/tests.o
	gcc -Wall -Werror build/main_test.o build/sort.o build/functions.o build/tests.o -o bin/test_app

build/main_test.o: test/main.c
	gcc -Wall -Werror -I thirdparty -I src -c test/main.c -o build/main_test.o 

build/tests.o: test/tests.c
	gcc -Wall -Werror -I thirdparty -I src -c test/tests.c -o build/tests.o

bin/sort_app: build/main.o build/functions.o build/sort.o
	gcc -Wall -Werror build/main.o build/functions.o build/sort.o -o bin/sort_app

build/functions.o: src/functions.c
	gcc -Wall -Werror -c src/functions.c -o build/functions.o 

build/sort.o: src/sort.c
	gcc -Wall -Werror -c src/sort.c -o build/sort.o 

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o 

clean:
	rm -rf build/*.o bin/sort_app bin/test_app

.PHONY: all clean test

