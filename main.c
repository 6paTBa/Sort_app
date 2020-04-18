#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "sort.h"

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
    if (size == 0) {
        printf("Unable to read data - invalid or empty data\n");
        fclose(input);
        return 0;
    }
    rewind(input);
    if (is_uint == 1) {
        uint32_t* arr_uint = malloc(sizeof(uint32_t) * size);
        for (size_t i = 0; i < size; i++) {
            fscanf(input, "%d", arr_uint + i);
        }
        count(arr_uint, size);
    } else {
        double* arr_double = malloc(sizeof(double) * size);
        for (size_t i = 0; i < size; i++) {
            fscanf(input, "%lf", arr_double + i);
        }
        if (size > 1000)
            mergesort(arr_double, 0, size - 1);
        else
            insertionsort(arr_double, size);
        fclose(input);
        return 0;
    }
}
