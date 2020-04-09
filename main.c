#include <inttypes.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE* input;
    if ((argc == 1) || (argc > 3)) {
        printf("Wrong number of arguments\n");
        return 0;
    }
    input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Unable to read data - file not found\n");
        return 0;
    }
    fclose(input);
    return 0;
}
