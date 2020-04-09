#include <inttypes.h>
#include <stdio.h>

size_t check_file(FILE* input)
{
    size_t size = 0;
    double buf;
    while (fscanf(input, "%lf", &buf) != EOF) {
        size++;
    }
    return size;
}
