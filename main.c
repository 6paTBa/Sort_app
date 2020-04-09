#include <inttypes.h>
#include <stdio.h>
#include "functions.h"

int main(int argc, char* argv[])
{
    FILE* input;
    if ((argc == 1) || (argc > 3)) {
        printf("Wrong number of arguments\n");
        return 0;
    }
    input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Unable to read data - file not found\n");
        return 0;
    }
	size_t is_uint = 1;
    size_t size = check_file(input,&is_uint);
    if (size == 0) {
        printf("Unable to read data - invalid or empty data\n");
        return 0;
    }
    fclose(input);
    return 0;
}
