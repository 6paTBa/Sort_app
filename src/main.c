#include "functions.h"
#define WRONG_ARGS_CODE 1
#define FILE_NOT_FOUND_CODE 2
#define SIMILAR_ARGS_CODE 3
#define INVALID_DATA_CODE 4

int main(int argc, char** argv)
{
    if ((argc == 1) || (argc > 3)) {
        display_error(WRONG_ARGS_CODE);
        return 0;
    }
    FILE* input;
    input = fopen(argv[1], "r");
    if (input == NULL) {
        display_error(FILE_NOT_FOUND_CODE);
        return 0;
    }
    if (argc == 3) {
        if (strcmp(argv[1], argv[2]) == 0) {
            display_error(SIMILAR_ARGS_CODE);
            return 0;
        }
    }
    size_t is_uint = 1;
    size_t size = check_file(input, &is_uint);
    if (size < 2) {
        display_error(INVALID_DATA_CODE);
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
    display_succes(argc, argv);
    return 0;
}
