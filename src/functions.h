#ifndef H_FUNCTIONS
#define H_FUNCTIONS
#include <stdio.h>
#include <stdlib.h>

void display_error(size_t code);

void display_succes(int argc, char** argv);

size_t check_uint(char* str, size_t i, size_t* point);

size_t check_null(char* str, size_t i);

size_t check_file(FILE* input, size_t* is_uint);

size_t check_string(char* str, size_t* is_uint);

void sort_uint(FILE* input, FILE* output, size_t size);

void sort_double(FILE* input, FILE* output, size_t size);
#endif
