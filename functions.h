#ifndef H_FUNCTIONS
#define H_FUNCTIONS
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

size_t check_file(FILE* input, size_t* is_uint);

int32_t check_string(char* str, size_t* is_uint);
#endif
