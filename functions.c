#include "sort.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR_LEN 50
#define MAX_IS_SIZE 1000

int32_t check_string(char* str, size_t* is_uint)
{
    size_t point = 0;
    if (strlen(str) == 1 && str[0] == '\n') {
        return 0;
    }
    for (size_t i = 0; str[i] != '\n'; i++) {
        if (i == 0 && str[i] == '-') {
            *is_uint = 0;
        } else if (i != 0 && str[i] == '.' && point == 0) {
            if (str[i - 1] == '-') {
                return 0;
            }
            point = 1;
            *is_uint = 0;
        } else if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

size_t check_file(FILE* input, size_t* is_uint)
{
    size_t size = 0;
    char str[MAX_STR_LEN];
    while (fgets(str, sizeof(str), input) != NULL) {
        if (check_string(str, is_uint) == 0) {
            return 0;
        }
        size++;
    }
    return size;
}

void sort_uint(FILE* input, FILE* output, size_t size)
{
    size_t i;
    uint32_t* arr_uint = malloc(sizeof(uint32_t) * size);
    for (i = 0; i < size; i++) {
        fscanf(input, "%d", arr_uint + i);
    }
    count(arr_uint, size);
    for (i = 0; i < size; i++) {
        fprintf(output, "%d\n", *(arr_uint + i));
    }
}

void sort_double(FILE* input, FILE* output, size_t size)
{
    size_t i;
    double* arr_double = malloc(sizeof(double) * size);
    for (i = 0; i < size; i++) {
        fscanf(input, "%lf", arr_double + i);
    }
    if (size > MAX_IS_SIZE) {
        mergesort(arr_double, 0, size - 1);
    } else {
        insertionsort(arr_double, size);
    }
    for (i = 0; i < size; i++) {
        fprintf(output, "%g\n", *(arr_double + i));
    }
}
