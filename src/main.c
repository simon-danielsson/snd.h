#include "main.h"
#include <stdio.h>

#define SND_IMPLEMENTATION
#include "../snd.h"

int main() {

    char *x = "x";
    char *y = "y";
    if (snd_are_diff(x, y)) {
        printf("they are different\n");
    };

    // FILE *f = fopen(".clangd", "r+");
    // char *c = snd_read_entire_file(f);
    // printf("%s\n", c);
    // free(c);

    return 0;
}
