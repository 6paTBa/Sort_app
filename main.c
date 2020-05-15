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
    size_t i;
    uint32_t* arr_uint;
    double* arr_double;
    if (is_uint == 1) {
        arr_uint = malloc(sizeof(uint32_t) * size);
        for (i = 0; i < size; i++) {
            fscanf(input, "%d", arr_uint + i);
        }
        fclose(input);
        count(arr_uint, size);
    } else {
        arr_double = malloc(sizeof(double) * size);
        for (i = 0; i < size; i++) {
            fscanf(input, "%lf", arr_double + i);
        }
        fclose(input);
        if (size > 1000) {
            mergesort(arr_double, 0, size - 1);
        } else {
            insertionsort(arr_double, size);
        }
    }
    FILE* output;
    if (argc == 3) {
        output = fopen(argv[2], "w");
    } else {
        output = fopen("sort.txt", "w");
    }
    if (is_uint == 1) {
        for (i = 0; i < size; i++) {
            fprintf(output, "%d\n", *(arr_uint + i));
        }
    } else {
        for (i = 0; i < size; i++) {
            fprintf(output, "%g\n", *(arr_double + i));
        }
    }
    fclose(output);
    return 0;
}
