#include "functions.h"

int main(int argc, char* argv[])
{
    if ((argc == 1) || (argc > 3)) {
        printf("Wrong number of arguments\n");
        return 0;
    }
    FILE* input;
    input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Unable to read data - file not found\n");
        fclose(input);
        return 0;
    }
    size_t is_uint = 1;
    size_t size = check_file(input, &is_uint);
    if (size < 2) {
        printf("Unable to sort data - invalid or empty data\n");
        fclose(input);
        return 0;
    }
    rewind(input);
    FILE* output;
    if (argc == 3) {
        output = fopen(argv[2], "w");
    } else {
        output = fopen("sort.txt", "w");
    }
    if (is_uint == 1) {
        sort_uint(input, output, size);
    } else {
        sort_double(input, output, size);
    }
    fclose(input);
    fclose(output);
    printf("Data from %s is succesfully sorted and printed in ", argv[1]);
    if (argc == 3) {
        printf("%s\n", argv[2]);
    } else {
        printf("sort.txt\n");
    }
    return 0;
}
