#include "sort.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR_LEN 50
#define MAX_IS_SIZE 1000

size_t check_uint(char* str, size_t i, size_t* point)
{
    if ((i == 0) && (str[i] == '-')) {
        return 1;
    }
    if ((i != 0) && (str[i] == '.') && (*point == 0)) {
        if ((str[i - 1] == '-') || (str[i + 1] == '\n')) {
            return 0;
        }
        *point = 1;
        return 1;
    }
    return 2;
}

size_t check_null(char* str, size_t i)
{
    if (str[i] == '0') {
        if (i == 0) {
            if ((str[i + 1] != '.') && (str[i + 1] != '\n')) {
                return 0;
            }
        } else if ((str[i - 1] == '-') && (str[i + 1] != '.')) {
            return 0;
        } else if (str[i + 1] == '.') {
            for (size_t j = 2; str[i + j] == '0'; j++) {
                if (str[i + j + 1] == '\n') {
                    return 0;
                }
            }
        }
    }
    return 1;
}

size_t check_string(char* str, size_t* is_uint)
{
    size_t point = 0;
    if (strlen(str) == 1 && str[0] == '\n') {
        return 0;
    }
    for (size_t i = 0; str[i] != '\n'; i++) {
        switch (check_uint(str, i, &point)) {
        case 0:
            return 0;
        case 1:
            *is_uint = 0;
            break;
        case 2:
            if (!isdigit(str[i])) {
                return 0;
            }
        }
        if (check_null(str, i) != 1) {
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
    uint32_t* arr_uint = calloc(size, sizeof(uint32_t));
    for (i = 0; i < size; i++) {
        fscanf(input, "%d", arr_uint + i);
    }
    counting_sort(arr_uint, size);
    for (i = 0; i < size; i++) {
        fprintf(output, "%d\n", *(arr_uint + i));
    }
    free(arr_uint);
}

void sort_double(FILE* input, FILE* output, size_t size)
{
    size_t i;
    double* arr_double = calloc(size, sizeof(double));
    for (i = 0; i < size; i++) {
        fscanf(input, "%lf", arr_double + i);
    }
    if (size > MAX_IS_SIZE) {
        merge_sort(arr_double, 0, size - 1);
    } else {
        insertion_sort(arr_double, size);
    }
    for (i = 0; i < size; i++) {
        fprintf(output, "%g\n", *(arr_double + i));
    }
    free(arr_double);
}
