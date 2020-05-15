#include <ctype.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#define MAX_STR_LEN 50

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
